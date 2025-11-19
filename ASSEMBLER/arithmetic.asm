; вычисление   5 * (A - B) - 2 * C + 5
; при          A = -2, B = 1; C = 5

TITLE first    ;название программы
.MODEL small   ;отводим под стек и под данные по 64Кб
.STACK 100h    ;отмечаем начало сегмента стека
.DATA          ;отмечаем начало сегмента данных
A DW -2        ;Здесь описаны переменные
B DW 1         ;
C DW 5         ;
D DW 2         ;        
.CODE          ;
main PROC      ;отмечаем начало сегмента кодов
MOV AX, @data   
MOV DS, AX     

MOV AX, A 	; занесено в AX число -2   
MOV BX, B   ; занесено в BX число 1          
SUB AX, BX  ; вычитание -3 - 1       результат -3   fffd в AX 
MOV BX, C   ; занесено в BX число 5  
MUL BX      ; умножение -3 * 5       результат -15  fff1 в AX            
MOV CX, AX  ; занесено в CX число -15 из AX  
MOV AX, D   ; занесено в AX число 2
MUL C       ; умножение 2 * 5        результат 10   a в AX           
SUB CX, AX  ; вычитание -15 - 10     результат -25  ffe7 в СX    
MOV AX, CX  ; занесено в AX число -25 из CX   
ADD AX, BX  ; сложение -25 + 5       результат -20  fffc в AX            
MOV AX,4C00h   ; выход из программы
INT 21h        
main ENDP 	  
END main	
