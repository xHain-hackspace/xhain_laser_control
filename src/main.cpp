//---------------------------------------------------------------
//  Demo program of Button class and ButtonGroup class
//
//  2016/02/22, Copyright (c) 2016 MIKAMI, Naoki
//---------------------------------------------------------------

#include "ButtonGroup.hpp"
#include "Label.hpp"

//PinPad
#define PINPAD_LEFT 200
#define PINPAD_TOP 40
#define PINPAD_WIDTH 50
#define PINPAD_HEIGHT PINPAD_WIDTH
#define PINPAD_GAP 3
//Names and Positions
const string PINPAD[12] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "Cancel", "0", "OK"};
#define PINPAD_1 0
#define PINPAD_2 1
#define PINPAD_3 2
#define PINPAD_4 3
#define PINPAD_5 4
#define PINPAD_6 5
#define PINPAD_7 6
#define PINPAD_8 7
#define PINPAD_9 8
#define PINPAD_CANCEL 9
#define PINPAD_0 10
#define PINPAD_OK 11


using namespace Mikami;

TS_DISCO_F746NG ts_;
LCD_DISCO_F746NG lcd_;

int main()
{

    Label LblTitle(4, 4, "xHain Laser Control", Label::LEFT, Font16);

    Label LblUser(4, 20, "No current user, please log in.", Label::LEFT, Font16);
 


    //create pinpad
    ButtonGroup pinpad(PINPAD_LEFT, PINPAD_TOP, PINPAD_WIDTH, PINPAD_HEIGHT, 12, PINPAD, PINPAD_GAP, PINPAD_GAP, 3);

    //set_time(1256729737);

    while (true)
    {
        pinpad.InactivateAll();
        pinpad.Activate(PINPAD_CANCEL);

        while (!pinpad.Touched(PINPAD_CANCEL)) ;//Wait for Button
        while(pinpad.GetTouchedNumber()!=-1);//wait for release
        pinpad.ActivateAll();       // Activate Pad

        int touch_nr;
        bool exit_pin_entry = false;
        string pin_str = "";

        while(1){
            time_t seconds = time(NULL);
            LblUser.Draw(ctime(&seconds));
        }

        while(!exit_pin_entry){
            while (!pinpad.GetTouchedNumber(touch_nr));//wait for touch
            switch (touch_nr)
            {
                case PINPAD_0: pin_str.append("0");
                    break;
                case PINPAD_1: pin_str.append("1");
                    break;
                case PINPAD_2: pin_str.append("2");
                    break;
                case PINPAD_3: pin_str.append("3");
                    break;
                case PINPAD_4: pin_str.append("4");
                    break;
                case PINPAD_5: pin_str.append("5");
                    break;
                case PINPAD_6: pin_str.append("6");
                    break;
                case PINPAD_7: pin_str.append("7");
                    break;
                case PINPAD_8: pin_str.append("8");
                    break;
                case PINPAD_9: pin_str.append("9");
                    break;
                case PINPAD_OK: pin_str.append("_OK");
                    exit_pin_entry = true;
                    break;
                case PINPAD_CANCEL: pin_str.append("_CANCEL");
                    exit_pin_entry = true;
                    break;   
            }
            while(pinpad.GetTouchedNumber()!=-1);//wait for release
            LblUser.Draw(pin_str);            
        }
    }
}

