;; ( + value value)
(defun isPlus(exp1)
    (if (equal (not (check-integer-value exp1)) nil)
        (+ (parse-integer (nth 1 exp1)) (parse-integer (nth 2 exp1)))
        nil
    )
)

;; ( - value value )
(defun isMinus(exp1)
    (if (equal (not (check-integer-value exp1)) nil)
        (- (parse-integer (nth 1 exp1)) (parse-integer (nth 2 exp1)))
        nil
    )
)

;; ( / value value )
(defun isDivide(exp1)
    (if (equal (not (check-integer-value exp1)) nil)
        (/ (parse-integer (nth 1 exp1)) (parse-integer (nth 2 exp1)))
        nil
    )
)

;; ( * value value )
(defun isMultiply(exp1)
    (if (equal (not (check-integer-value exp1)) nil)
        (* (parse-integer (nth 1 exp1)) (parse-integer (nth 2 exp1)))
        nil
    )
)

;; ( ** value value)
(defun isDoubleStar(exp1)
    (if (equal (not (check-integer-value exp1)) nil)
        (return-from isDoubleStar (DBMULTI (parse-integer (nth 1 exp1)) (parse-integer (nth 2 exp1))))
        nil
    )
)

;; ( and binary binary )
(defun isAnd(exp1)
    (if (equal (not (check-binary-value exp1)) nil)
        (progn 
            (setq resultB (and (change-binary-value (nth 1 exp1)) (change-binary-value (nth 2 exp1))))
            (if (equal resultB T)
                (return-from isAnd "true")
                (return-from isAnd "false")
            )
        )
        nil
    )
)

;; ( or binary binary )
(defun isOr(exp1)
    (if (equal (not (check-binary-value exp1)) nil)
        (progn 
            (setq resultB (or (change-binary-value (nth 1 exp1)) (change-binary-value (nth 2 exp1))))
            (if (equal resultB T)
                (return-from isOr "true")
                (return-from isOr "false")
            )
        )
        nil
    )
)

;; ( not binary )
(defun isNot(exp1)
    (if (equal (not (check-binary-value exp1)) nil)
        (progn 
            (setq resultB (not (change-binary-value (nth 1 exp1))))
            (if (equal resultB T)
                (return-from isNot "true")
                (return-from isNot "false")
            )
        )
        nil
    )
)

;; ( equal binary binary ) veya ( equal value value ) 
(defun isEqual(exp1)
    (if (equal (not (check-binary-value exp1)) nil)
        (progn 
            (setq resultB (equal (change-binary-value (nth 1 exp1)) (change-binary-value (nth 2 exp1))))
            (if (equal resultB T)
                (return-from isEqual "true")
                (return-from isEqual "false")
            )
        )
        (progn 
            (if (equal (not (check-integer-value exp1)) nil)
                (progn 
                    (setq resultB (equal (parse-integer (nth 1 exp1)) (parse-integer (nth 2 exp1))))
                    (if (equal resultB T)
                        (return-from isEqual "true")
                        (return-from isEqual "false")
                    )
                )
                nil
            )
        )
    )
)

;; ( less value value ) 
(defun isLess(exp1)
    (if (equal (not (check-integer-value exp1)) nil)
        (progn 
            (setq resultB (< (parse-integer (nth 1 exp1)) (parse-integer (nth 2 exp1))))
            (if (equal resultB T)
                (return-from isLess "true")
                (return-from isLess "false")
            )
        )
        nil
    )
)

;; ( set id value ) or ( set id value ) 
;;print value or value
(defun isSet(exp1) 
    (if (equal (parse-integer (nth 2 exp1) :junk-allowed t) nil)
        (progn 
            (if (equal (type-of (nth 2 exp1)) 'CONS)
                (return-from isSet (nth 2 exp1))
                (return-from isSet nil)
            )
        )
        (return-from isSet (parse-integer (nth 2 exp1)))
    )
)

;;only integer value
(defun isList(exp1)
    (setq controlValue 0)
    (setq returnList '())
    (dolist (element exp1) 
        (if (equal controlValue 1)
            (progn 
                (if (equal (parse-integer element :junk-allowed t) nil)
                    (progn 
                        (setq liste1 (read-from-string element))
                        (if (equal (type-of liste1) 'CONS)
                            (setq returnList (append returnList (list liste1)))
                            (return-from isList nil)
                        )
                    )
                    (setq returnList (append returnList (list (parse-integer element)))) 
                )
            )
        )
        (setq controlValue 1)
    )
    (return-from isList returnList)
)

;; ( append value value ) or ( append value value )
(defun isAppend(exp1) 
    (setq liste1 '())
    (setq liste2 '())
    (setq liste1 (read-from-string (nth 1 exp1)))
    (setq liste2 (read-from-string (nth 2 exp1)))
    (if (equal (type-of liste2) 'CONS)
        (progn 
            (if (equal (parse-integer (nth 1 exp1) :junk-allowed t) nil)
                (progn 
                    (if (equal (type-of liste1) 'CONS)
                        (progn 
                            (setq liste2 (append liste1 liste2))
                            (return-from isAppend liste2) 
                        )
                    )
                    nil
                )
                (progn 
                    (setq liste2 (append liste2 (parse-integer (nth 1 exp1))))
                    (return-from isAppend liste2)
                )
            )
        )
        nil
    )
)

;; concat value value
(defun isConcat(exp1)
    (setq liste1 '())
    (setq liste2 '())
    (setq liste1 (read-from-string (nth 1 exp1)))
    (setq liste2 (read-from-string (nth 2 exp1)))   
    (if (and (equal (type-of liste1) 'CONS) (equal (type-of liste2) 'CONS))
        (return-from isConcat (concat-lists liste1 liste2))
        nil
    )
)

;; ( if EXP_BINARY EXPLIST_INTEGER ) veya ( if EXP_BINARY EXPLIST_INTEGER EXPLIST_INTEGER )
;; About binary value that returns false. And, it returns first or second list about binary value
(defun isIfCondition(exp1)
    (setq EX_BI (nth 1 exp1))
    (if (equal (or (equal EX_BI "true") (equal EX_BI "false") (equal EX_BI "\"true\"") (equal EX_BI "\"false\"")) nil)
        (return-from check-binary-value nil)
        (progn 
            (cond 
                ((equal (length exp1) 3)
                    (progn 
                        (if (or (equal EX_BI "false") (equal EX_BI "\"false\""))
                            (return-from isIfCondition "false")
                            (progn 
                                (setq liste2 '())
                                (setq liste2 (read-from-string (nth 2 exp1)))
                                (if (equal (type-of liste2) 'CONS)
                                    (return-from isIfCondition liste2)
                                    nil
                                )     
                            )
                        )                    
                    )
                )
                ((equal (length exp1) 4)
                    (progn 
                        (setq liste1 '())
                        (setq liste2 '())
                        (setq liste1 (read-from-string (nth 2 exp1)))
                        (setq liste2 (read-from-string (nth 3 exp1)))   
                        (if (and (equal (type-of liste1) 'CONS) (equal (type-of liste2) 'CONS))
                            (progn 
                                (if (or (equal EX_BI "true") (equal EX_BI "\"true\""))
                                    (return-from isIfCondition liste1)
                                    (return-from isIfCondition liste2)
                                )
                            )
                            nil
                        )
                    )
                )
                (t nil)
            )
        )
    )
)

;; if binary value
;; about binary value return false.
(defun isWhileLoop(exp1) 
    (setq EX_BI (nth 1 exp1))
    (if (equal (or (equal EX_BI "true") (equal EX_BI "false") (equal EX_BI "\"true\"") (equal EX_BI "\"false\"")) T)
        (progn 
            (if (or (equal EX_BI "false") (equal EX_BI "\"false\""))
                (return-from isWhileLoop "false")
                (progn 
                    (setq liste2 '())
                    (setq liste2 (read-from-string (nth 2 exp1)))
                    (if (equal (type-of liste2) 'CONS)
                        (return-from isWhileLoop liste2)
                        nil
                    )     
                )
            )
        )
    )
)

(defun isLoadKeyword(exp1)
    (if (type-of (nth 1 exp1) 'simple-array)
        (return-from isLoadKeyword (nth 1 exp1))
        nil
    )
)


;; deffun require special syntx control 
;; deffun controlled made previous controllings.If come to this point it is okey.
(defun itisDeffun(exp1)
    (format t "SYNTAX OK. ~%")
)
