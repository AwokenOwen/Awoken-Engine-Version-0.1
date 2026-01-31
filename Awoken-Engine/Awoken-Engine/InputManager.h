#pragma once
#include "void_event.h"
#include "float_2_event.h"
#include "GLFW/glfw3.h"

#define Input InputManager::getInstance()

class InputManager
{
public:
	//start the input manager
	int Initialize();

	//free any data on the heap
	int Terminate();

	//singleton get function
	static InputManager& getInstance();

	//Input function for mouse movement
	void mouseMove(float posx, float posy);

	//Process all key presses on the window and transfer them to Events
	void processInputs(GLFWwindow* window);

#pragma region Key and Mouse Events

	//All key events
	void_event Escape, Escape_Pressed, Escape_Released;
	void_event F1, F1_Pressed, F1_Released;
	void_event F2, F2_Pressed, F2_Released;
	void_event F3, F3_Pressed, F3_Released;
	void_event F4, F4_Pressed, F4_Released;
	void_event F5, F5_Pressed, F5_Released;
	void_event F6, F6_Pressed, F6_Released;
	void_event F7, F7_Pressed, F7_Released;
	void_event F8, F8_Pressed, F8_Released;
	void_event F9, F9_Pressed, F9_Released;
	void_event F10, F10_Pressed, F10_Released;
	void_event F11, F11_Pressed, F11_Released;
	void_event F12, F12_Pressed, F12_Released;
	void_event Grave, Grave_Pressed, Grave_Released;
	void_event One, One_Pressed, One_Released;
	void_event Two, Two_Pressed, Two_Released;
	void_event Three, Three_Pressed, Three_Released;
	void_event Four, Four_Pressed, Four_Released;
	void_event Five, Five_Pressed, Five_Released;
	void_event Six, Six_Pressed, Six_Released;
	void_event Seven, Seven_Pressed, Seven_Released;
	void_event Eight, Eight_Pressed, Eight_Released;
	void_event Nine, Nine_Pressed, Nine_Released;
	void_event Zero, Zero_Pressed, Zero_Released;
	void_event Minus, Minus_Pressed, Minus_Released;
	void_event Equals, Equals_Pressed, Equals_Released;
	void_event Backspace, Backspace_Pressed, Backspace_Released;
	void_event Tab, Tab_Pressed, Tab_Released;
	void_event Q, Q_Pressed, Q_Released;
	void_event W, W_Pressed, W_Released;
	void_event E, E_Pressed, E_Released;
	void_event R, R_Pressed, R_Released;
	void_event T, T_Pressed, T_Released;
	void_event Y, Y_Pressed, Y_Released;
	void_event U, U_Pressed, U_Released;
	void_event I, I_Pressed, I_Released;
	void_event O, O_Pressed, O_Released;
	void_event P, P_Pressed, P_Released;
	void_event LeftBracket, LeftBracket_Pressed, LeftBracket_Released;
	void_event RightBracket, RightBracket_Pressed, RightBracket_Released;
	void_event Backslash, Backslash_Pressed, Backslash_Released;
	void_event Caps, Caps_Pressed, Caps_Released;
	void_event A, A_Pressed, A_Released;
	void_event S, S_Pressed, S_Released;
	void_event D, D_Pressed, D_Released;
	void_event F, F_Pressed, F_Released;
	void_event G, G_Pressed, G_Released;
	void_event H, H_Pressed, H_Released;
	void_event J, J_Pressed, J_Released;
	void_event K, K_Pressed, K_Released;
	void_event L, L_Pressed, L_Released;
	void_event SemiColon, SemiColon_Pressed, SemiColon_Released;
	void_event Apostrophe, Apostrophe_Pressed, Apostrophe_Released;
	void_event Enter, Enter_Pressed, Enter_Released;
	void_event LeftShift, LeftShift_Pressed, LeftShift_Released;
	void_event Z, Z_Pressed, Z_Released;
	void_event X, X_Pressed, X_Released;
	void_event C, C_Pressed, C_Released;
	void_event V, V_Pressed, V_Released;
	void_event B, B_Pressed, B_Released;
	void_event N, N_Pressed, N_Released;
	void_event M, M_Pressed, M_Released;
	void_event Comma, Comma_Pressed, Comma_Released;
	void_event Period, Period_Pressed, Period_Released;
	void_event ForwardSlash, ForwardSlash_Pressed, ForwardSlash_Released;
	void_event RightShift, RightShift_Pressed, RightShift_Released;
	void_event LeftControl, LeftControl_Pressed, LeftControl_Released;
	void_event LeftAlt, LeftAlt_Pressed, LeftAlt_Released;
	void_event Space, Space_Pressed, Space_Released;
	void_event RightAlt, RightAlt_Pressed, RightAlt_Released;
	void_event RightControl, RightControl_Pressed, RightControl_Released;
	void_event Insert, Insert_Pressed, Insert_Released;
	void_event Home, Home_Pressed, Home_Released;
	void_event Delete, Delete_Pressed, Delete_Released;
	void_event End, End_Pressed, End_Released;
	void_event PageUp, PageUp_Pressed, PageUp_Released;
	void_event PageDown, PageDown_Pressed, PageDown_Released;
	void_event Up, Up_Pressed, Up_Released;
	void_event Down, Down_Pressed, Down_Released;
	void_event Left, Left_Pressed, Left_Released;
	void_event Right, Right_Pressed, Right_Released;
	void_event Divide, Divide_Pressed, Divide_Released;
	void_event Multiply, Multiply_Pressed, Multiply_Released;
	void_event Dash, Dash_Pressed, Dash_Released;
	void_event Addition, Addition_Pressed, Addition_Released;
	void_event Submit, Submit_Pressed, Submit_Released;
	void_event Decimal, Decimal_Pressed, Decimal_Released;
	void_event NumZero, NumZero_Pressed, NumZero_Released;
	void_event NumOne, NumOne_Pressed, NumOne_Released;
	void_event NumTwo, NumTwo_Pressed, NumTwo_Released;
	void_event NumThree, NumThree_Pressed, NumThree_Released;
	void_event NumFour, NumFour_Pressed, NumFour_Released;
	void_event NumFive, NumFive_Pressed, NumFive_Released;
	void_event NumSix, NumSix_Pressed, NumSix_Released;
	void_event NumSeven, NumSeven_Pressed, NumSeven_Released;
	void_event NumEight, NumEight_Pressed, NumEight_Released;
	void_event NumNine, NumNine_Pressed, NumNine_Released;
	void_event MouseOne, MouseOne_Pressed, MouseOne_Released;
	void_event MouseTwo, MouseTwo_Pressed, MouseTwo_Released;
	void_event MouseThree, MouseThree_Pressed, MouseThree_Released;
	float_2_event MouseOffset;
	float_2_event MousePosition;
	
#pragma endregion

private:
	InputManager();

	//mouse movement variables
	bool firstMouse = true;
	float lastx, lasty;

#pragma region bools
	bool Escape_bool;
	bool F1_bool;
	bool F2_bool;
	bool F3_bool;
	bool F4_bool;
	bool F5_bool;
	bool F6_bool;
	bool F7_bool;
	bool F8_bool;
	bool F9_bool;
	bool F10_bool;
	bool F11_bool;
	bool F12_bool;
	bool Grave_bool;
	bool One_bool;
	bool Two_bool;
	bool Three_bool;
	bool Four_bool;
	bool Five_bool;
	bool Six_bool;
	bool Seven_bool;
	bool Eight_bool;
	bool Nine_bool;
	bool Zero_bool;
	bool Dash_bool;
	bool Equals_bool;
	bool Backspace_bool;
	bool Tab_bool;
	bool Q_bool;
	bool W_bool;
	bool E_bool;
	bool R_bool;
	bool T_bool;
	bool Y_bool;
	bool U_bool;
	bool I_bool;
	bool O_bool;
	bool P_bool;
	bool LeftBracket_bool;
	bool RightBracket_bool;
	bool BackSlash_bool;
	bool Caps_bool;
	bool A_bool;
	bool S_bool;
	bool D_bool;
	bool F_bool;
	bool G_bool;
	bool H_bool;
	bool J_bool;
	bool K_bool;
	bool L_bool;
	bool SemiColon_bool;
	bool Apostrophe_bool;
	bool Enter_bool;
	bool LeftShift_bool;
	bool Z_bool;
	bool X_bool;
	bool C_bool;
	bool V_bool;
	bool B_bool;
	bool N_bool;
	bool M_bool;
	bool Comma_bool;
	bool Period_bool;
	bool ForwardSlash_bool;
	bool RightShift_bool;
	bool LeftControl_bool;
	bool LeftAlt_bool;
	bool Space_bool;
	bool RightAlt_bool;
	bool RightControl_bool;
	bool Insert_bool;
	bool Home_bool;
	bool Delete_bool;
	bool End_bool;
	bool PageUp_bool;
	bool PageDown_bool;
	bool Up_bool;
	bool Down_bool;
	bool Right_bool;
	bool Left_bool;
	bool Divide_bool;
	bool Multiply_bool;
	bool Minus_bool;
	bool Addition_bool;
	bool Submit_bool;
	bool NumZero_bool;
	bool NumOne_bool;
	bool NumTwo_bool;
	bool NumThree_bool;
	bool NumFour_bool;
	bool NumFive_bool;
	bool NumSix_bool;
	bool NumSeven_bool;
	bool NumEight_bool;
	bool NumNine_bool;
	bool Decimal_bool;
	bool MouseOne_bool;
	bool MouseTwo_bool;
	bool MouseThree_bool;
#pragma endregion
};