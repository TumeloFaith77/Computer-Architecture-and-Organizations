.data
    isPrime: .word 1
    notPrime: .word 0
    true: .word 1
    false: .word 0
    reversetrue: .word 1
    
    
.text
.globl main
     main:
        #$t0 = a
        #$t1 = b
        #t2 = c
        #t3 = d
        #t4 = y
        
        li $t4, 0
        
        
     loop2:
        li $t0, 0             #a=0
        sge $t5, $t0, $zero   #a>=0 and stores it in $t5
        jal reverse
        seq $t6, $t0, 1     #set return(a) as true
        seq $t1, $t1, $t6   #set to b for b= reverse(a)
        
        li $v0, 10
        syscall
     
    #checks if a number is prime
     primeChecker:  
          #$t0=x
          #$t1=i
     
          li $t1, 2      #sets i = 2

           #exclude a number less than or equal to 1
           blt $t0, 1, notPrime
           beq $t0, 1, notPrime
     
           #initialise the lowest prime number 2
           beq $t0, 2, isPrime
     
           div $t0, $t1       #x/i
           mfhi $t2          #store the quotient in $t2
           beq $t2, 0, notPrime      #if the quotient is equal to zero then x is not prime
           addi $t1, $t1, 1        #increment i(i++)
           
           b primeChecker
     
     #checks if a number is perfect
     isPerfect:
         
         #$t4 = x
         li $t0, 0  #the parameter passed to the function
         li $t1, 1  #sets sum = 1
         li $t2, 2  #sets i=2
         
         mul $t3, $t2, $t2  #stores the product of i by i into $t3
         sle $t5, $t3, $t4   #sts product of i by i less or equal to x and stores it in register 13
         addi $t2, $t2, 1  #increments i
         div $t4, $t2   #division of x by i
         mfhi $t5     #stores the remainder
         beq $t5, 0, loop #if(x%i==0) then branch to loop
         
         loop:
             bne $t3, $t4, sum
            
         sum:
            div $t4, $t2  #division of x by i
            mflo $t6  #storing the quotient in $t6
            add $t1, $t1, $t2  #adding sum plus i and storing it in sum
            add $t1, $t1, $t6 #adding new sum and the quotient(x/i)
            b end  #branch to end
            
        end:
            add $t1, $t1, $t2  #add sum and i and store in sum
            b loop
            
        boolean:
            sne $t4, $t4, 1
            beq $t1, $t4, true 
            b false  
            
        while:
             #$t0=x
             #$t1=rem
             #$t2=reverse
             
             li $t4, 10   #stores 10 in registor 12
             sne $t0, $t0, 1   #set x not equal to 1
             div $t0, $t4   #divides x by 10
             mfhi $t1       #stores the remaider in $t1
             mul $t3, $t2, $t4   #reverse*10 stored in $t3
             add $t2, $t3, $t1   #9reverse*10) + rem stored in reverse
             add $t0, $t0, $t4   #add x and 10 and store in x
             move $a0, $t2
             jal reverse
             
        reverse:
            li $t2, 0   #sets reverse to 0
            j while
            li $v0, 1
            la, $a0, reverse
            syscall
            
                        
         notPlindrome:
                                                      
               
                   
              
             
             
             
                                                                   
             
            
          
           
                         
          
          