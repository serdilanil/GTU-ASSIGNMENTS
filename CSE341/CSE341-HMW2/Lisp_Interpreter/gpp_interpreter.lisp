(setq KEYWORDS_LIST '("and" "or" "not" "equal" "less" "nil" "list" "append" "concat" "set" "deffun" "for" "if" "exit" "load" "disp" "true" "false" "while"))
(setq KEYWORDS_TOKEN_LIST '("KW_AND" "KW_OR" "KW_NOT" "KW_EQUAL" "KW_LESS" "KW_NIL" "KW_LIST" "KW_APPEND" "KW_CONCAT"
                            "KW_SET" "KW_DEFFUN" "KW_FOR" "KW_IF" "KW_EXIT" "KW_LOAD" "KW_DISP" "KW_TRUE" "KW_FALSE" "KW_WHILE"))

(setq OPERATORS_LIST '("+" "-" "/" "*" "(" ")" "**" """" ","))
(setq OPERATORS_TOKEN_LIST '("OP_PLUS" "OP_MINUS" "OP_DIV" "OP_MULT" "OP_OP" "OP_CP" "OP_DBLMULT" "OP_OC" "OP_CC" "OP_COMMA"))

(setq TOKENS_LIST '())


(defun read-file (filename)
  (with-open-file (stream filename)
    (loop for line = (read-line stream nil)
          while line
            collect line
    )
  )
)


(defun is-character(ch)
    (and (<= (char-code ch) 122) (>= (char-code ch) 65))
)


(defun is-number(nb)
    (and (<= (char-code nb) 57) (>= (char-code nb) 48)) 
)


(defun is-space (ch)
    (= (char-code ch) 32)
)


(defun searchList (str liste)
    (dotimes (index (length liste))
        (if (equal (nth index liste) str)
            (return-from searchList index)
        )
    )
    nil
)


(defun trim-list (list)
    (setq newList '())
    (dolist (line list)
        (setq resultString "")
        (loop for ch across line
            do 
                (cond
                    ((equal (string ch) "(") (setq resultString (concatenate 'string resultString (string "( "))))
                    ((equal (string ch) ")") (setq resultString (concatenate 'string resultString (string " )"))))
                    (t (setq resultString (concatenate 'string resultString (string ch))))
                )
        )
        (setq newList (append newList (list resultString)))
    )
    newList
)


(defun return-error-message (strORch)
    (setq error "SYNTAX__ERROR ")
    (setq error2 " cannot be tokenized")
    (setq error (concatenate 'string error (string strORch)))
    (setq error (concatenate 'string error error2))
    error
)


(defun is-identifier-or-number (str)
    (setq ch-number 0)
    (setq nb-number 0)
    (setq ifisFirst 0)
    (setq syntax_control nil)

    (loop for c across str do
        (if (equal ifisFirst 0)
            (if (is-number c) 
                (progn 
                    (setq syntax_control T)
                    (setq ifisFirst 1)
                )
                (setq ifisFirst 1)
            )
        )
        (if (is-character c)
            (setq ch-number (+ ch-number 1))
        )
        (if (is-number c)
            (setq nb-number (+ nb-number 1))
        )
    )
    (if (equal (length str) ch-number)
        (return-from is-identifier-or-number "IDENTIFIER")

    )
    (if (equal (length str) nb-number)
        (return-from is-identifier-or-number "VALUE")

    )
    (if (equal syntax_control T)
        (progn 
            (return-from is-identifier-or-number (return-error-message str))

        )
        (return-from is-identifier-or-number "IDENTIFIER")
    )
)


(defun determine-tokens-name (line) 
    (setq controlComma 0)
    (setq controlSpace 0)
    (setq tokens '())
    (setq word "")
    (setq integers "")
    (loop for ch across line do 
        
        (cond 
            ( (equal ch #\;) 
                (if (equal controlComma 0)
                    (setf controlComma 1)
                    (progn 
                        (setf controlComma 0)
                        (setq tokens (append tokens (list '("COMMENT"))))
                        (return-from determine-tokens-name tokens)
                    )
                )
            )

            ((equal ch #\*) 
                (if (equal controlComma 0)
                    (setf controlComma 1)
                    (progn 
                        (setf controlComma 0)
                        (setq tokens (append tokens (list '("OP_DBLMULT" "**"))))
                    )
                )

            )

            ( (not (eq (searchList (string ch) OPERATORS_LIST) nil))
                
                (setq index (searchList (string ch) OPERATORS_LIST))
                (setq tokens (append tokens (list (list (nth index OPERATORS_TOKEN_LIST) (string ch)))))
            )

            ( (not (equal (is-character ch) nil))
                
                (setf word (concatenate 'string word (string ch)))
            )

            ( (not (equal (is-number ch) nil))
                
                (setf word (concatenate 'string word (string ch)))
                (setf integers (concatenate 'string integers (string ch)))
            )

            ( (equal (is-space ch) t)
                
                (setq controlSpace 1)
                (if (not (equal word ""))
                    (progn 
                        (if (not (equal (searchList word KEYWORDS_LIST) nil))
                            (progn 
                                (setq index (searchList word KEYWORDS_LIST)) ;; If is keyword ...
                                (setq tokens (append tokens (list (list (nth index KEYWORDS_TOKEN_LIST) word))))
                                (setq word "")  
                            )
                            (progn 
                                
                                (setq tokens (append tokens (list (list (is-identifier-or-number word) word))))
                                (setq word "")
                            )
                        )
                    )
                )                           
            )
            
            (t (setq tokens (append tokens (list (list (return-error-message ch) (string ch))))))
        )
    )
    (return-from determine-tokens-name tokens)
)


(defun helper-lexer (liste)
    (dolist (line liste)
        (setq TOKENS_LIST (append TOKENS_LIST (determine-tokens-name line)))
    )
    TOKENS_LIST
)


(defun print-tokens (liste)
    (terpri)
    (dolist (line liste)
        (format t "~a~%" line)
    )
    (terpri)
)


(defun gpp_lexer (file_string)
    (setq TOKENS_LIST '())
    (setq string-list '())
    (setq new-string-list '())

    (setq file-list '())
    (setq file-list (append file-list (list file_string)))
    
    (setf new-string-list (trim-list file-list))
    (helper-lexer new-string-list)
    (return-from gpp_lexer TOKENS_LIST)
)



(setq KEYWORDS_LIST '("and" "or" "not" "equal" "less" "nil" "list" "append" "concat" "set" "deffun" "for" "if" "exit" "load" "disp" "true" "false" "while"))
(setq OPERATORS_LIST '("+" "-" "/" "*" "(" ")" "**" """" ","))

;; delete the last of list
(defun remove-last-element (list)
    (loop for l on list
        while (rest l)
        collect (first l)
    )
)

;; reverse list
(defun reverse-list (l)
    (cond
        ((null l) '())
        (T (append (reverse-list (cdr l)) (list (car l))))
    )
) 

;; concat the two list
(defun concat-lists(seq1 seq2)
    (cond ((not (null seq1)) (cons (car seq1) (concat-lists (cdr seq1) seq2)))
          (T (cond ((not (null seq2)) (cons (car seq2) (concat-lists seq1 (cdr seq2))))
                   (T nil))))
)

(defun string-include (strA strB)
    (cond
        ((zerop (length strA)) nil) 
        ((> (length strA) (length strB)) nil) 
        ((string= strA (subseq strB 0 (length strA))) strA) 
        (t (string-include strA (subseq strB 1)))
    )
) 

(defun check-tokens(Arr)
    (setq OPcount 0)
    (setq CPcount 0)
    (setq deffunControl 0)
    (dolist (subList Arr)
        (if (equal (nth 0 subList) "OP_OP")
            (setq OPcount (+ OPcount 1))
        )
        (if (equal (nth 0 subList) "OP_CP")
            (setq CPcount (+ CPcount 1))
        )
        (if (not (equal (string-include "SYNTAX__ERROR" (nth 0 subList)) nil))
            (progn 
                (if (not (equal (nth 1 sublist) "'"))
                    (return-from check-tokens nil)
                )
            )
        )
        (if (equal (nth 0 subList) "KW_DEFFUN")
            (setq deffunControl 1)
        )
    )

    (if (not (equal OPcount CPcount))
        (return-from check-tokens nil)
        (progn 
            (if (equal deffunControl 1)
                (return-from check-tokens "itisDeffun")
                (return-from check-tokens T)
            )
        )
    )
)


(load "helper.lisp")


(defun check(exp1) 
    (cond 
        ( (not (equal (searchList (nth 0 exp1) OPERATORS_LIST) nil))
            
            (progn 
                (cond 
                    ( (equal (nth 0 exp1) "+") 
                        (if (equal (length exp1) 3)
                            (progn 
                                (setq result (isPlus exp1))
                                (return-from check result)
                            )
                            nil
                        )
                    )
                    ( (equal (nth 0 exp1) "-") 
                        (if (equal (length exp1) 3)
                            (progn 
                                (setq result (isMinus exp1))
                                (return-from check result)
                            )
                            nil
                        )
                    )
                    ( (equal (nth 0 exp1) "/") 
                        (if (equal (length exp1) 3)
                            (progn 
                                (setq result (isDivide exp1))
                                (return-from check result)
                            )
                            nil
                        )
                    )
                    ( (equal (nth 0 exp1) "*") 
                        (if (equal (length exp1) 3)
                            (progn 
                                (setq result (isMultiply exp1))
                                (return-from check result)
                            )
                            nil
                        )
                    )
                    ( (equal (nth 0 exp1) "**") 
                        (if (equal (length exp1) 3)
                            (progn 
                                (setq result (isDoubleStar exp1))
                                (return-from check result)
                            )
                            nil
                        )
                    )
                )
            )
        )
        ( (not (equal (searchList (nth 0 exp1) KEYWORDS_LIST) nil))
            
            (cond 
                ( (equal (nth 0 exp1) "and") 
                    (if (equal (length exp1) 3)
                        (progn 
                            (setq result (isAnd exp1))
                            (return-from check result) 
                        )
                        nil
                    )
                )
                ( (equal (nth 0 exp1) "or") 
                    (if (equal (length exp1) 3)
                        (progn 
                            (setq result (isOr exp1))
                            (return-from check result) 
                        )
                        nil
                    )
                )
                ( (equal (nth 0 exp1) "not") 
                    (if (equal (length exp1) 2)
                        (progn 
                            (setq result (isNot exp1))
                            (return-from check result) 
                        )
                        nil
                    )
                )
                ( (equal (nth 0 exp1) "equal") 
                    (if (equal (length exp1) 3)
                        (progn 
                            (setq result (isEqual exp1))
                            (return-from check result) 
                        )
                        nil
                    )
                )
                ( (equal (nth 0 exp1) "less") 
                    (if (equal (length exp1) 3)
                        (progn 
                            (setq result (isLess exp1))
                            (return-from check result) 
                        )
                        nil
                    )
                )
                ( (equal (nth 0 exp1) "set") 
                    (if (equal (length exp1) 3)
                        (progn 
                            (setq result (isSet exp1))
                            (return-from check result) 
                        )
                        nil
                    )
                )
                ( (equal (nth 0 exp1) "list") 
                    (progn 
                        (setq result "")
                        (if (equal (length exp1) 1) 
                            (setq result "NIL")
                            (setq result (isList exp1))
                        )
                        (return-from check result)
                    )  
                )
                ( (equal (nth 0 exp1) "append") 
                    (progn 
                        (setq result (isAppend exp1))
                        (return-from check result)
                    )  
                )
                ( (equal (nth 0 exp1) "concat")  
                    (if (equal (length exp1) 3)
                        (progn 
                            (setq result (isConcat exp1))
                            (return-from check result) 
                        )
                        nil
                    )
                )
                ( (equal (nth 0 exp1) "if")  
                    (progn 
                        (setq result (isIfCondition exp1))
                        (return-from check result) 
                    )
                    nil
                )
                ( (equal (nth 0 exp1) "while") 
                    (if (equal (length exp1) 3)
                        (progn 
                            (setq result (isWhileLoop exp1))
                            (return-from check result) 
                        )
                        nil
                    )
                )
                ( (equal (nth 0 exp1) "deffun") 
                    (return-from check "SYNTAX OK.")     
                )
                ( (equal (nth 0 exp1) "load") 
                    (if (equal (length exp1) 2)
                        (progn 
                            (setq result (isLoadKeyword exp1))
                            (return-from check result)   
                        )
                        nil
                    ) 
                )
            )
        )
        (t nil)
    )
)

(defun parserSup(string_)

    (setq stack1 '())
    (setq stack2 '())
    (setq word "")
    (setq controlFirst T)
    (setq listControl nil)
    (setq previousCH #\1)

    (loop for ch across string_ do 

        (if (equal controlFirst T)
            (progn 
                (if (equal (or (equal ch (code-char 39.)) (equal ch (code-char 40))) T)
                    (progn 
                        (if (equal ch (code-char 39.)) 
                            (setq listControl T)
                        )
                        (setq controlFirst nil)
                    )
                    (progn 
                        (format t "~%SYNTAX_ERROR Expression not recognized~%")
                        (return-from parserSup nil)
                    )
                )
            )
            (progn
                (cond 
                    ((equal ch (code-char 41.)) 
                        (progn 
                            (setq rev-stack1 (reverse-list stack1))
                            (dolist (element rev-stack1) 
                                (if (equal element (string (code-char 40.)))
                                    (progn 
                                        (setq stack1 (remove-last-element stack1)) 
                                        (return)
                                    )
                                    (progn 
                                        (setq stack2 (append stack2 (list element)))
                                        (setq stack1 (remove-last-element stack1)) 
                                    ) 
                                )
                            )
                            (setq stack2 (reverse-list stack2))  
                            (setq control (check stack2))
                            (if (equal control nil)
                                (progn 
                                    (format t "~%SYNTAX_ERROR Expression not recognized~%")
                                    (return-from parserSup nil)
                                )
                                (progn 
                                    (setq stack2 '())
                                    (setq stack1 (append stack1 (list (write-to-string control))))
                                )                    
                            )
                        )
                    )

                    ((equal ch #\space) 
                        (progn 
                            (if (not (equal word ""))
                                (progn 
                                    (setq stack1 (append stack1 (list word))) 
                                    (setq word "")
                                )
                            )
                        )
                    )
                    
                    ((equal listControl T) 
                        (progn 
                            (if (equal ch (code-char 40.))
                                (progn 
                                    (setq stack1 (append stack1 (list "list")))
                                    (setq listControl nil)
                                )
                            )
                        )   
                    )

                    ((not (equal ch #\;))    
                        (progn 
                            (if (and (equal previousCH #\') (equal ch (code-char 40.)))
                                (progn 
                                    (setq stack1 (append stack1 (list "(")))
                                    (setq stack1 (append stack1 (list "list")))
                                    (setq word "")
                                )
                                (setf word (concatenate 'string word (string ch)))
                            )
                        )   
                    )
                )
            )
        )
        (setq previousCH ch)
	)

    (if (equal (nth 0 stack1) "\"true\"")
        (format t "true")
        (progn 
            (if (equal (nth 0 stack1) "\"false\"")
                (format t "false")
                (progn 
                    (if (not (equal (nth 0 stack1) nil))
                        (format t "~a" (nth 0 stack1))
                    )
                )
            )
        )
    )
    (terpri)
)

(defun gppinterpreter() 
    (format t "-       *****************       ~%")
    (format t "-        use this format for execute g++ example.g++~%")
    (setq counter 0)
    (setq counter (+ counter 1))
    (loop 
        (format t "-----> " )
        (setq read_string (string-downcase (string (read-line))))
        (if (equal (string-include "g++" read_string) nil)
            (progn 
                (if (not (equal read_string "exit"))
                    (progn 
                        (setq controlLOAD 0) (setq counter (+ counter 1)) (setq tokens '())
                        (setq list_ '()) (setq list_ (append list_ (list read_string)))
                        (setq read_string (nth 0 (trim-list list_)))
                        
                        (if (not (equal (string-include "( load" read_string) nil))
                            (progn
                                (format t "~%~a~%" (subseq read_string 6 (- (length read_string) 1)))
                                (setq controlLOAD 1)
                            )
                        )
                        (if (equal controlLOAD 0)
                            (progn 
                                (setq tokens (gpp_lexer read_string))
                                (if (not (equal (check-tokens tokens) nil))
                                    (progn 
                                        (if (equal (check-tokens tokens) "itisDeffun")
                                            (itisDeffun tokens)
                                            (parserSup read_string)
                                        )
                                    )
                                    (format t "~%SYNTAX_ERROR Expression not recognized~%")
                                )
                            )
                        )
                    )
                    (format t "Finish.")
                )
            )
            (progn 
                (setq counter (+ counter 1))
                (setq read_string (subseq read_string 4 (length read_string)))
                (setq line2 "")
                (let ((in (open read_string :if-does-not-exist nil)))
                    (when in
                        (loop for line = (read-line in nil)
                            while line do 
                            (progn 
                                (setq line2 line)
                                (setq list_ '())
                                (setq list_ (append list_ (list line)))
                                (setq read_string (nth 0 (trim-list list_)))
                                (parserSup read_string)
                            )
                        )
                        (close in)
                    )
                )
            )
        )
        
        (when (equal read_string "exit") (return ))
    )
)

(defun check-binary-value(exp1)
    (setq controlValue 0)
    (dolist (element exp1) 
        (if (equal controlValue 1)
            (progn 
                (if (equal (or (equal element "true") (equal element "false") (equal element "\"true\"") (equal element "\"false\"")) nil)
                    (return-from check-binary-value nil)
                )
            )
        )
        (setq controlValue 1)
    )
    T
)


(defun DBMULTI(numA numB)
    (setq result 1)
    (setq control 0)
    (loop 
        (setq result (* result numA))
        (setq control (+ control 1))
        (when (equal control numB) (return-from DBMULTI result))
    )
)

(defun change-binary-value(trueORfalse)
    (if (or (equal trueORfalse "true")  (equal trueORfalse"\"true\""))
        T
        nil
    )
)


(defun check-integer-value(exp1)
    (setq controlValue 0)
    (dolist (element exp1) 
        (if (equal controlValue 1)
            (progn 
                (if (equal (parse-integer element :junk-allowed t) nil)
                    (return-from check-integer-value nil)
                )
            )
        )
        (setq controlValue 1)
    )
    T
)

(gppinterpreter)


