#include <stdio.h>
#include <math.h>
//Name: Mohamed Ali
//Date: 9/13/2021
//This program uses the sliding nth digit algorithm to calculate the nth root of a given number between 2 and 1000000.
//This program uses several variables within loops in order to accurately calculate the nth root and print it out
//towards the end of the program.
int main() {
    setbuf(stdout,0);
    int A; //This is where I define my integers to use in my calculations.
    int n;
    int k;
    double x;
    int y;
    double r;
    int alpha;
    int beta;
    double div;
    int group;
    int i;
    int q;
    int bac;
    int con;
    int f;
    int aa;
    int counter;
    int z;
    int nextm;
    double u;
    int c1;
    int c2;
    int p;
    double raise;
    double found;
    double raise2;
    double nn;
    double result1;
    double result2;
    double tenn;
    double estimate;

    found = 0; //initializing variables to use in my calculations
    p = 1;
    nextm = 1;
    z = 0;
    aa = 1;
    q = 1;
    con = 1;
    tenn = 10;

    printf("Number: "); //this part of the code is for printing the inputs from the user
    scanf("%d", &A);

    printf("Root: ");
    scanf("%d", &n);

    printf("Digits: ");
    scanf("%d", &k);

    printf("Compute root %d of %d to %d digits.\n", n, A, k);//this prints a restatement of the code's purpose

    for(i = 0; i<n; i++){   //for loop for calculating 10^n
        q = (q*10);
    }
    group= A/q; // integer math used for grouping the input number
    if(group == 0){
        i=1; //i indicates number of groups
        alpha = A;
        counter = alpha; //counter is used for the first iteration of the calculations
    }

    else{
        i = 1;
        while(group>0){ //while loop used for calculating number of groups if there is more than one group
            group = group/q;
            i = i+1;
        }
        for(bac=0; bac< i; bac++){  // for loop used for determining the correct power of 10
            con = (con*10);
            z++; // increment offset
        }
        con = A/con;
        alpha = con;
        while(alpha>10){    //while loop used for calculating correct value for first alpha
            alpha = alpha/10;
            counter = alpha;
            z++;
        }
    }
    counter = alpha;

    printf("Number has %d groups of %d digits.\n", i, n); //prints number of groups and n power

    y = 0;
    r = 0;
    beta = 0; // initializing variables in order to perform calculations
    f = i + k; //f indicates number of iterations to run through loop
    c2 = i;// c2 is used for another counter without messing with initial number of groups
    c1 = 0;
    nn = n; // nn is used for pow calculations because it is a double


    while(f>0){ //start of big nested loop in order to calculate needed values
        while(aa>0){
            printf("alpha = %d, ", counter);
            u = (q*r)+counter;
            while(found<=u && (beta>=0 && beta<=9)){ //while loop for finding beta and still meeting conditions
                raise = ((10*y)+beta);
                raise2 = (10*y);
                result1 = pow(raise, nn);
                result2 = pow(raise2, nn);
                found = (result1 - result2);
                if(found<=u){ //increment beta if meet conditions
                    ++beta;
                }
                else if (found>u){
                    --beta; //decrement if it does not
                    raise = ((10*y)+beta);
                    result1 = pow(raise, nn);
                    found = (result1 - result2);
                    break;
                }
            }
            printf("beta = %d\n", beta);
            y = (10*y)+beta; //used for finding y
            r = u - found; // r is found by subtracting upper limit from found
            if(r<0){
                r = 0; // checks for overflow
            }
            printf("y = %d, r = %.0f\n", y, r);

            --aa;
            --f; //decrement counter
        }
        for(c1 = c1; c1<z; c1++){
            nextm = (nextm*10);
        }
        if(p>0){    //series of if statement to get next alpha
            alpha = A % nextm;
        }

    if(alpha > q){
        alpha = alpha / q;
    }
    else if(alpha<10){
        alpha = 0;
    }
    printf("alpha = %d, ", alpha);
    u = (q*r)+alpha;
    while(found<=u && (beta>=0 && beta<=9)){    //same while loop as before to get beta
        raise = ((10*y)+beta);
        raise2 = (10*y);
        result1 = pow(raise, nn);
        result2 = pow(raise2, nn);
        found = (result1 - result2);
        if(found<=u){
            ++beta;
        }
        else if (found>u){
            --beta;
            raise = ((10*y)+beta);
            result1 = pow(raise, nn);
            found = (result1 - result2);
            break;
        }
    }
    if(beta>9){
        beta = 9;
    }
    if(found>u){for(u=u; found>u; --beta){ //for loop to make sure beta is the correct value
        raise = ((10*y)+beta);
        result1 = pow(raise, nn);
        found = (result1 - result2); //also helps to avoid r becoming negative
    }
    ++beta;
    }
    if(beta<0){
        beta=0;
    }
        printf("beta = %d\n", beta);

        y = (10*y)+beta;
        r = u - found;
        if(r<0){
            r = 0;
        }
        printf("y = %d, r = %.0f\n", y, r);

    alpha = A % nextm;
    alpha = alpha % q; //divide and modulo used to get next alpha value
    --p;
    --f; // decrement counter

    if(c2>=i && f>0 && A/(q*10)>0){ // if statement to indicate alpha is correct
        printf("alpha = %d, ", alpha);
        u = (q*r)+alpha; // used to find upper limit
        while(found<=u && (beta>=0 && beta<=9)){
            raise = ((10*y)+beta);
            raise2 = (10*y);
            result1 = pow(raise, nn);
            result2 = pow(raise2, nn);
            found = (result1 - result2);
            if(found<=u){
                ++beta;
            }
            else if (found>u){
                --beta;
                raise = ((10*y)+beta);
                result1 = pow(raise, nn);
                found = (result1 - result2);
                break;
            }
        }

        if(beta>9){ // makes sure beta meets conditions
            beta=9;
        }
        if(found>u){for(u=u; found>u; --beta){
            raise = ((10*y)+beta);
            result1 = pow(raise, nn);
            found = (result1 - result2);
        }
        ++beta;
        }
        if(beta<0){
            beta=0;
        }
        printf("beta = %d\n", beta);
        y = (10*y)+beta;
        r = u - found;
        if(r<0){
            r = 0;
        }
        printf("y = %d, r = %.0f\n", y, r);

        --f;
        --c2;
    }

    else if(f>0){
        alpha = 0;
        printf("alpha = %d, ", alpha);
        u = (q*r)+alpha;
        while(found<=u && (beta>=0 && beta<=9)){    //more loops to get correct value of beta
            raise = ((10*y)+beta);
            raise2 = (10*y);
            result1 = pow(raise, nn);
            result2 = pow(raise2, nn);
            found = (result1 - result2);

            if(found<=u){
                ++beta;
            }
            else if (found>u){
                --beta;
                raise = ((10*y)+beta);
                result1 = pow(raise, nn);
                found = (result1 - result2);
                break;
            }
        }
        if(beta>9){
            beta = 9;
        }
        if (found>u){   // if found is higher than upper limit, beta does not meet conditions
            --beta;
        }

        if(found>u){for(u=u; found>u; --beta){  // ensures correct value of beta and r
            raise = ((10*y)+beta);
            result1 = pow(raise, nn);
            found = (result1 - result2);
        }
        ++beta;
        }
        if (beta<0){
            beta = 0;
        }
        printf("beta = %d\n", beta);
        y = (10*y)+beta;
        r = u - found;
        if(r<0){
            r = 0;
        }
        printf("y = %d, r = %.0f\n", y, r);

        --f;
        --c2;
    }
}
    printf("\n"); // end of large nested loop


    estimate = pow(tenn, k); // raises 10^k
    x = y/estimate;
    printf("Estimated root = %lf\n", x);
    div = pow(x, nn);   //takes root^n
    printf("Check: %lf to the %d = %lf (orig = %d)\n", x, n, div, A); //prints final statement, purpose of
    //code has been fulfilled


    return 0;
}
