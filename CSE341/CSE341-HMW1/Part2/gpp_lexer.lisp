(defun interpret-shell()
	(loop (format t "~%>>> ") (interpreter (read-line))))


(defun interpret-file (fileName)
	(let ((in (open fileName :if-does-not-exist nil)))
		(when in
			(loop for line = (read-line in nil) while line do
				(interpreter line out))
			(close in))
		(unless in
			(format t "Error! No such file: '~a'~%" fileName))))


(defun interpreter(temp)
	
	(let ((lst (input-to-lst temp)))
		(if (string= (car lst) ";;") (print "COMMENT")  
		(map nil #'(lambda (token) (print (tokenize token (get-token)))) lst))
	))

;;parse token 
(defun get-token ()

	(let((token-key '("and" "or" "not" "equal" "less" "nil" "list"
	 	 			 "append" "concat" "set" "deffun" "for" "if" 
	 	 			 "exit" "load" "disp" "true" "false" "+" "-" 
	 	 			 "/" "*" "(" ")" "**" ","))
		 (token-value '("KW_AND" "KW_OR" "KW_ NOT" "KW_EQUAL" "KW_LESS" 
					   "KW_NIL" "KW_LIST" "KW_APPEND" "KW_CONCAT" "KW_SET" 
					   "KW_DEFFUN" "KW_FOR" "KW_IF" "KW_EXIT" "KW_LOAD" 
					   "KW_DISP" "KW_TRUE" " KW_FALSE" "OP_PLUS" "OP_MINUS"
					   "OP_DIV" "OP_MULT" "OP_OP" "OP_CP" "OP_DBLMULT" "OP_COMMA")))
		(pairlis token-key token-value)))

	

(defun tokenize (token lst)

	 ;; Start state of DFA.
	 ;; Scan the first char and direct it to proper state.
	 (let ((c (string (char token 0)))) 
	 (cond ((is-alphap c) (tokenize-identifier token lst))  ;; [a-zA-z] identifier and kw
	 	   ((is-numeric c) (tokenize-value token))			;; [0-9] value
	 	   ((is-quo c) (tokenize-string token))
	 	   (t (if (tokenize-op token lst) 					;; operator
	 	   (tokenize-op token lst) (errout token c))))))	;; else, syntax error.



;;Identifier situation to DFA start [0-9azAZ]
(defun tokenize-identifier (token lst)
	
	(assert (is-alphap (string (char token 0))))

	;; Scanning one by one.
	(loop for c across token 
		do (if (not (or (is-alphap c) (is-numeric c))) 
		(return-from tokenize-identifier (errout token c))))

	(let ((kw (tokenize-kw token lst)))
		(if (null kw) (format nil "IDENTIFIER") kw)))
	

;;parse token value
(defun tokenize-value (token)
	
	(assert (is-numeric (string (char token 0))))

	;; [0] --> value 
	(if (and (> (length token) 1) (is-zerop (substring token 0 1))) 
		(return-from tokenize-value (errout token (substring token 0 1))))

	;; [0-9] --> value <--- [0-9]*
	(loop for c across token 
		do (if (not (is-numeric c))
		(return-from tokenize-value (errout token c))))
	(format nil "VALUE"))

(defun tokenize-kw (token lst)
	
	 (let ((value (assoc token lst :test #'string=)))
		(if value (format nil "~a" (cdr value)) nil)))

(defun tokenize-op (token lst)

	 (let ((value (assoc token lst :test #'string=)))
		(if value (format nil "~a" (cdr value)) nil)))

;;Token strings
(defun tokenize-string (token)
	
	(assert (is-quo (string (char token 0))))
	(format nil "STRING"))

;;Error function
(defun errout (token c)
	(format nil "SYNTAX ERROR: '~a' : '~a'" token c))

(defun list-to-string (lst)
    (format nil "~{~A~}" lst))


(defun is-bracketsp (chr)
	(or (char= chr #\() (char= chr #\))))


(defun is-zerop (chr)
	(eq (char-code (coerce chr 'character)) 48));; ->0


(defun is-semicolonp (chr)
	(char= chr #\;))

	
(defun is-quo (chr)
	(eq (char-code (coerce chr 'character)) 34));; ->"

(defun is-numeric (chr)
	

	(let ((c (char-int (coerce chr 'character))))
		(and (>= c (char-int #\0)) (<= c (char-int #\9)))))
	
(defun is-alphap (chr)

	(let ((c (char-int (coerce chr 'character))))
		(and (>= c (char-int #\A)) (<= c (char-int #\z)))))


;;ignore space newline backspace tab return
(defun cleanup (str)

	(let ((trim-lst '(#\Space #\Newline #\Backspace #\Tab #\Return )))
	(string-trim trim-lst str)))

;;splits key sequence 
(defun split-space (string &key (is-spacep #'is-spacep))

  (loop :for start = (position-if-not is-spacep string)
    :then (position-if-not is-spacep string :start (1+ end))
    :for end = (and start (position-if is-spacep string :start start))
    :when start :collect (subseq string start end)
    :while end))


(defun is-spacep (c)
	(or (and (char>= c (code-char 9)) (char<= c (code-char 13))) (char= c (code-char 32))))


(defun input-to-lst (str)
	(when (is-not-zero str)
		(let ((founded (fpos-delim str)) (fchr) (pos) (posQuote))
			(unless (null founded) (setf fchr (car founded)) (setf pos (cdr founded)))

			(cond 
				((null founded) (list str))
				((is-bracketsp fchr)
					(if (zerop pos)
						(cons (subseq str 0 1) (input-to-lst (subseq str 1)))
						(cons (subseq str 0 pos) (cons (subseq str pos (+ pos 1)) (input-to-lst (subseq str (+ pos 1)))))))
				((is-spacep fchr)
					(if (zerop pos)
						(input-to-lst (subseq str 1))
						(cons (subseq str 0 pos) (input-to-lst (subseq str (+ pos 1))))))
				((is-quote fchr)
					(if (zerop pos)
						(cons (subseq str 0 1) (input-to-lst (subseq str 1)))
						(cons (subseq str 0 pos) (cons (subseq str pos (+ pos 1)) (input-to-lst (subseq str (+ pos 1)))))))
				(t (if (or (<= (length str) (+ pos 1)) (not (is-semicolonp (char str (+ pos 1)))))
						(if (zerop pos)
							(cons (subseq str 0 1) (input-to-lst (subseq str 1)))
							(cons (subseq str 0 pos) (cons (subseq str pos (+ pos 1)) (input-to-lst (subseq str (+ pos 1))))))
						(if (zerop pos) (list str) (list (subseq str 0 pos) (subseq str pos)))))))))

(defun is-not-zero (str)
	(not (zerop (length str))))


(defun is-quote (chr)
	(char= chr #\"))

(defun fpos-delim (str &optional (pos 0))
	(when (is-not-zero str)
	3	(if (or (is-bracketsp (char str 0)) (is-spacep (char str 0)) (is-semicolonp (char str 0)) (is-quote (char str 0)))
			(cons (char str 0) pos)
			(fpos-delim (subseq str 1) (+ pos 1)))))


(defun gppinterpreter (&optional filename)
	(if filename (interpret-file filename) (interpret-shell))
	)

(if *args* (gppinterpreter (car *args*)) (gppinterpreter))