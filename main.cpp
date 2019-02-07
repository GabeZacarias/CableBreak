#include <iostream>
#include <iomanip>                                                                      //for cout set precision


using namespace std;


//Function declarations
void user_input(double& cableLength, double& CableThickness);

double compute_stretch(double cableThickness, double cableLength);

void compute_output(int tension, double stretch);


//Function call
int main()
{
    double cableLength, cableThickness, stretch, tension;

        user_input(cableLength, cableThickness);

        stretch = compute_stretch(cableLength, cableThickness);

	return 0;
}



//Function definitions
void user_input(double& cableLength, double& cableThickness)                        //double&
{
    cableLength = 0;
    cableThickness = 0;

    while (cableLength <= 0)
        {
            cout << "Enter the length of the cable in feet: ";
            cin >> cableLength;
                if (cableLength <= 0)                                               //if else statement with brackets required
                    {
                        cout << endl;
                        cout << "This is not a valid length.";
                        cout << endl << endl;
                    }
        }
    while (cableThickness <= 0 || cableThickness > 2.0)
        {
            cout << "Enter the thickness of the cable up to 2.0 inches: ";
            cin >> cableThickness;
                if (cableThickness <= 0 || cableThickness > 2.0)                    //if else statement with brackets required
                    {
                        cout << endl;
                        cout << "The thickness must be 2.0 inches or less.";
                        cout << endl << endl;
                    }
        }
}


//Definitions
double compute_stretch(double cableLength, double cableThickness)
{
    int tension = 0;
    double stretch = cableLength;                                                      // New/Stretched Length

    while (stretch < (cableLength * 1.16))
        {
            tension++;
            stretch = stretch + (cableThickness * 0.3);
            compute_output(tension, stretch);
        }
            cout << endl;
            cout << "The cable has broken!" << endl;

    return(stretch);
}



void compute_output(int tension, double stretch)
{
    cout << fixed << setprecision(2);                                                   //set precision to hundreth place
    cout << endl;
    cout << "The tension applied to the cable is: " << tension << " lbs." << endl;
    cout << "The length of the cable is: " << stretch << " feet." << endl;
}
