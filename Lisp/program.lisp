; Count lists in list
(defun f1 (list)
  ; if list is empty, return 0
  (cond ((null list) 0)
        ; list is not empty, make sure list is actually of type list, if it is then add 1 and move on
        ((listp (car list)) (+ 1 (f1 (cdr list))))
        ; else recursive call without incrementing
        (t (f1 (cdr list)))
        )
)

; Decide if list has atom inside
(defun f2 (list)
  ; if list is empty, return nil
  (cond ((null list) nil)
  ; check if the first item of list is an atom, if yes return t
  ((atom (car list)) t)
  ; recursively call on rest of list
  (t (f2 (cdr list))))
)

; Return list with only odd integers
(defun f3 (n)
  ; check if list is empty
   (cond ((null n) nil)
         ; check if odd
         ((oddp (car n))
          ; cons the head of the list
           (cons (car n)
                 ; recursive call on rest of list
                 (f3 (cdr n))))
         ; otherwise, just recursive call on rest of n
         (t (f3 (cdr n))))
)

; Determine min value in integer list
(defun f4 (list)
  ; check if list is empty
  (cond ((null list) nil)
  ; if the rest of list is null, return the head
  ((null (cdr list)) (car list))
  ; if the head is less than the head of the tail, cons the car and recursive call
  (( < (car list)(car (cdr list))) (f4 (cons (car list) (cdr (cdr list)))))
  ; otherwise only recursive call
  ( t (f4 (cdr list))))
)

; reverse a list
(defun f5 (l)
  ; check if list is null
    (cond ((null l) nil)
  ; list isn't null, append the tail onto the head
    ((append (f5 (cdr l)) (list (car l)))))
)

; return every other element in a list
(defun f6 (l)
  ; check if list is null
    (cond ((null l) nil)
   ; check if tail is null
    ((null (cdr l)) nil)
    ; cons the head of list onto the tail of tail
    (t (cons (car l) (f6(cdr (cdr l))))))
)

; return element at given position in list
(defun f7(l i)
  ; if counter/index is 0, return that element
    (cond ((equal i 0) (car l))
    ; otherwise, go to next element and decrement i
        (t (f7 (cdr l) (- i 1))))
)

; return product of all integers in list
(defun f8 (l)
    ; if the list is a single number, return the number
    (cond ((numberp l) l)
      ; if the tail is null, recursive call on the head
        ((null (cdr l)) (f8 (car l)))
       ; otherwise, multiply the recursive head of l with the recursive tail
        (t (* (f8 (car l)) (f8 (cdr l))))))

; helper function for f9
(defun rmv (e l)
    (cond ((null l) nil)
    ((equal (car l) e) (rmv e (cdr l)))
    ( t (cons (car l) (rmv e (cdr l))))))

; remove duplicates in a list
(defun f9 (l)
  ; if list is null return nil
    (cond ((null l) nil)
    ; otherwise, recursively call our rmv helper function on the head of l as the element, and the tail of l as the list
    (t (cons (car l) (f9 (rmv (car l) (cdr l)))))))

; helper function for f10
(defun mbr(e l)
    (cond ((null l) nil)
    ((equalp (car l) e) T)
    (t (mbr e (cdr l)))))

; intersection of two lists
(defun f10 (l1 l2)
  ; check if first list is null
    (cond ((null l1) nil)
   ; if the head of l1 is a member of l2, cons the head of l1 onto the recursive call of the tail of l1 and l2
    ((mbr (car l1) l2) (cons (car l1) (f10 (cdr l1) l2)))
    ; otherwise, just do the recursive call
    (t (f10 (cdr l1) l2))))