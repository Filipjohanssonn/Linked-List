# NY VERSION
# Karlstads Universitet
# Kurs: DVGA03
# Uppgift: Laboration 1
# Namn: Filip Johansson
# Datum: 2021-09-23
# Källor/Insporation: 
# - https://minnie.tuhs.org/CompArch/Resources/mips_quick_tutorial.html
# - https://github.com/hakjong/mips-qsort/blob/master/quick.s
# - https://zzun.net/662

	.data
vek: .word 4,5,2,2,1,6,7,9,5,10 # Reserverar plats i ram för 10 heltal och lägger in talen i minnescellerna.
vektorStorlek: .space 4
radbrytning: .asciiz "\n"
space: .asciiz " "

 	.text
 	.globl main
main:
	la $t0, vektorStorlek # Flyttar vektorStorlek adress till register $t0
	la $t1, vek # Flyttar vektorns adress till register $t1
	sub $t2, $t0, $t1 # $t2 = $t0 - $t1. $t0: 0x10010028 -  $t1: 0x10010000 = $t2: 0x00000028
	srl $t2, $t2, 2 # $t2 = $t2 / 2^2 = 40 / 4 = 10. (10 i hex = 0x0000000a) Får fram antal element i vektor. 
	sw $t2, 0($t0) # Copy from register to memory

# quickSort & skriv 
	la $a0, vek # Flyttar vektorns adress till register $a0
	li $a1, 0 # $a1 = 0
	lw $t0, vektorStorlek # load vektorStorlek till register: $t0
	addi $t0, $t0, -1 # $t0 = $t0 + (-1) = vektorStorlek - 1
	move $a2, $t0 # Kopierar värdet i register $t0 till $a2
	jal quickSort # Anropar subrutin QUICKSORT
	jal skriv # Anropar subrutin skriv
	li $v0, 10 # $v0 = 10. (10) i $v0 = exit (terminate execution)
	syscall
	
# ********************** Subrutin skriv som skall skriva ut vektorn. **********************
skriv: 
	la $s0, vek # Flyttar vek adress till register $s0
	lw $t0, vektorStorlek # load vektorStorlek till register: $t0
	L1: 
	beq $t0, $zero, L2 # Hoppa till L2 om $t0 == $zero
	li $v0, 4 # $v0 = 4 (4) i $v0: $a0 = address of null-terminated string to print
	la $a0, space
	syscall # Skriver ut " "
	li $v0, 1 # (4) i $v0: $a0 = integer to print
	lw $a0, 0($s0) # Load 0($s0) till $a0 = lägg vektor till $a0 för utskrift. load vektorStorlek till register: $t0
	syscall # Skriv ut vektor element
	addi $t0, $t0, -1 # $t0 = $t0 + (-1) = vektorStorlek - 1 
	addi $s0, $s0, 4 # $s0 = $s0 + 4	
	j L1

	L2: 
	li $v0, 4
	la $a0, radbrytning # Skriver ut "\n" för att få radbrytning.  
	syscall
	jr $ra # Hoppar till "return adressen"
	
# ********************** Subrutin quickSort som skall sortera vektorn. **********************
quickSort:        
	slt $t0, $a1, $a2 # Om $a1 < $a2, $t0 = 1. Annars är $t0 = 0 a1(=p):starting position a2(=r):ending position
        beq $t0, $zero, quickSortReturn # Om $t0 = $zero, branch till return
        addi $t0, $t0, 0x0 # Konstant till register $t0

        subu $sp, $sp, 16 # Flyttar stackpekaren
        sw $ra, 16($sp) # Sparar returadressen
        sw $a0, 12($sp) # a0 = Vektorns plats i registret
        sw $a1, 8($sp) # Behövs för Subrutin partition
        sw $a2, 4($sp) # Behövs för Subrutin partition 
        jal partition # Anropar subrutin partition (v[], a, b)

        subu $sp, $sp, 4 # Flyttar stackpekaren
        sw $v0, 4($sp) # Spara returvärdet (upper) från partition (=q)
        lw $a0, 16($sp)
        lw $a1, 12($sp) # Load vektor[] till $a1 - load v[], a
        ori $a2, $v0, 0 # Flytta returvärdet (upper (q)) till $a2
        jal quickSort # Anropa subrutin quickSort (v[], a, k-1) ***** quickSort(v, a, k-1);

        lw $a0, 16($sp) # Load vektor[]
        lw $t0, 4($sp) # Load returvärdet (upper (q)) till $t0q
        addi $a1, $t0, 1 # a1 = (upper (q)) + 1
        lw $a2, 8($sp) # Load b
        jal quickSort # quickSort(v[], q+1, b) ******* quickSort(v, k+1, b);
        addi $t0, $t0, 0x0 # Konstant till register $t0

        addu $sp, $sp, 20 # Flyttar tillbaka stackpekaren
        lw $ra, 0($sp) # Återställer retur-adressenaddress

	quickSortReturn: 
	jr $ra # Hoppar till "return adressen"

# ********************** Subrutin partition som skall "grovsortera" vektorn. **********************
partition:
	add $t0, $a1, $a1 # $t0 = $a1 + $a1
        add $t0, $t0, $t0 # t0 = $t0 + $t0
        add $t0, $t0, $a0 # t0 = v[] + t0
        lw  $t0, 0($t0) # t0 = v[a]
        addi $t1, $a1, -1 # i = a - 1
        addi $t2, $a2, 1 # j = b + 1 
        add $t3, $t1, $t1 # $t3 = i + i
        add $t3, $t3, $t3 # $t3 = $t3 + $t3
        add $t3, $t3, $a0 # $t3 = $t3 + v[] = v[i] // För att minska loopen
        add $t4, $t2, $t2 # $t4 = $t2 + $t2
        add $t4, $t4, $t4 # $t4 = $t4  $t4
        add $t4, $t4, $a0 # $t4 = $t4 + v[] = v[j]

	Loop1:                
	addi $t1, $t1, 1 # i = i + 1
        addi $t3, $t3, 4 # $t3 = $t3 + 4. // För att återställa adressen för v[i]
        lw $t5, 0($t3) # Load $t3 till register $t5
        slt $t6, $t5, $t0 # Om $t5 < $t0, $t6 = 1. Annars 0. (Om $t5 < v[a])
        bne $t6, $zero, Loop1 # Om $t6 != $zero, branch till Loop1
        addi $t0, $t0, 0x0 # Konstant till register $t0nop

	Loop2:
	addi $t2, $t2, -1 # j = j - 1
        addi $t4, $t4, -4 # $t4 = $t4 - 4 // För återställning av adressen v[j]. 
        lw $t5, 0($t4) # Load $t4 till register $t5
        slt $t6, $t0, $t5 # Om $t0 < $t5, $t6 = 1. Annars 0.  
        bne $t6, $zero, Loop2 # Om $t6 != $zero, branch till Loop2  // if v[j] > x, branch to Loop1

        slt $t5, $t1, $t2 # Om $t1 < $t2, $t5 = 1. Annars 0
        beq $t5, $zero, partitionReturn # Om $t5 == $zero, branch till return // if i >= j, branch to return
        
	# Swap
        lw $t5, 0($t3) # Load $t3 till register $t5
        lw $t6, 0($t4) # Load $t4 till register $t6
        sw $t6, 0($t3) # Load $t3 till register $t6
        sw $t5, 0($t4) # Load $t4 till register $t5 // swap v[i] and A[j]
        beq $zero, $zero, Loop1 # branch till Loop1

	partitionReturn:
	addu $v0, $zero, $t2 # v0 = j
        jr $ra  # Hoppar till "return adressen"
        