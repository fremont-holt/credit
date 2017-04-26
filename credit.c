#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

long get_card_number();
int get_check_digits( long card_number );
int get_number_of_digits( long card_number );
void get_card_type( char *card_type, int length, int check_digit );

int main( void )
{
    char card_type[13];
    
    long card_number = get_card_number();
    int check_digit = get_check_digits( card_number );
    int length = get_number_of_digits( card_number );
    get_card_type( card_type, length, check_digit );
    
    printf( "%s", card_type );
    
    return 0;
}

//Gets a card number from user between 13 and 16 digits
long get_card_number()
{
    printf( "Number: " );
    long input = get_long_long();
  
    return input;
}

//Get's the check digits (first two of card number)
int get_check_digits( long card_number )
{
    int digits = (int) log10( card_number ) - 1; // length of number minus two
    int check_digit = (int) ( card_number / pow( 10, digits ) ); //Get the first two digits
    return check_digit;
}

//Gets the number of digits in given long long
int get_number_of_digits( long card_number )
{
    int length = (int) (log10(card_number) + 1);
    return length;
}

//Returns the type of card from the info given
void get_card_type( char *card_type, int length, int check_digit )
{
    switch( check_digit )
    {
        //Mastercard should begin with 51 through 54 and be 16 digits long
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
            if( length == 16 )
            {
                strcpy( card_type, "MASTERCARD\n");
                break;
            }
            strcpy( card_type, "INVALID\n");
            break;
        //AMEX should begin with 34 or 37 and be 15 digits long
        case 34:
        case 37:
            if( length == 15 )
            {
                strcpy( card_type, "AMEX\n");
                break;
            }
            strcpy( card_type, "INVALID\n");
            break;
        //Visa should begin with 4 and be 13 or 16 digits long
        case 40 ... 49:
            if( length == 13 || length == 16 )
            {
                strcpy( card_type, "VISA\n");
                break;
            }
            strcpy( card_type, "INVALID\n");
            break;
        default:
            strcpy( card_type, "INVALID\n");
            break;
    }
}