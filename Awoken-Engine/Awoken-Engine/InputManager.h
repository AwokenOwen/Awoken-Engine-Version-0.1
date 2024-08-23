#pragma once
#include "Event.h"
#include "MouseEvent.h"
#include "GLFW/glfw3.h"

#define Input InputManager::getInstance()

class InputManager
{
public:
	//start the input manager
	int Start();

	//free any data on the heap
	int Stop();

	//singleton get function
	static InputManager& getInstance();

	//Input function for mouse movement
	void mouseMove(float posx, float posy);

	//Process all key presses on the window and transfer them to Events
	void processInputs(GLFWwindow* window);

#pragma region Key and Mouse Events

	//All key events
	Event Escape, Escape_Pressed, Escape_Released;
	Event F1, F1_Pressed, F1_Released;
	Event F2, F2_Pressed, F2_Released;
	Event F3, F3_Pressed, F3_Released;
	Event F4, F4_Pressed, F4_Released;
	Event F5, F5_Pressed, F5_Released;
	Event F6, F6_Pressed, F6_Released;
	Event F7, F7_Pressed, F7_Released;
	Event F8, F8_Pressed, F8_Released;
	Event F9, F9_Pressed, F9_Released;
	Event F10, F10_Pressed, F10_Released;
	Event F11, F11_Pressed, F11_Released;
	Event F12, F12_Pressed, F12_Released;
	Event Grave, Grave_Pressed, Grave_Released;
	Event One, One_Pressed, One_Released;
	Event Two, Two_Pressed, Two_Released;
	Event Three, Three_Pressed, Three_Released;
	Event Four, Four_Pressed, Four_Released;
	Event Five, Five_Pressed, Five_Released;
	Event Six, Six_Pressed, Six_Released;
	Event Seven, Seven_Pressed, Seven_Released;
	Event Eight, Eight_Pressed, Eight_Released;
	Event Nine, Nine_Pressed, Nine_Released;
	Event Zero, Zero_Pressed, Zero_Released;
	Event Minus, Minus_Pressed, Minus_Released;
	Event Equals, Equals_Pressed, Equals_Released;
	Event Backspace, Backspace_Pressed, Backspace_Released;
	Event Tab, Tab_Pressed, Tab_Released;
	Event Q, Q_Pressed, Q_Released;
	Event W, W_Pressed, W_Released;
	Event E, E_Pressed, E_Released;
	Event R, R_Pressed, R_Released;
	Event T, T_Pressed, T_Released;
	Event Y, Y_Pressed, Y_Released;
	Event U, U_Pressed, U_Released;
	Event I, I_Pressed, I_Released;
	Event O, O_Pressed, O_Released;
	Event P, P_Pressed, P_Released;
	Event LeftBracket, LeftBracket_Pressed, LeftBracket_Released;
	Event RightBracket, RightBracket_Pressed, RightBracket_Released;
	Event Backslash, Backslash_Pressed, Backslash_Released;
	Event Caps, Caps_Pressed, Caps_Released;
	Event A, A_Pressed, A_Released;
	Event S, S_Pressed, S_Released;
	Event D, D_Pressed, D_Released;
	Event F, F_Pressed, F_Released;
	Event G, G_Pressed, G_Released;
	Event H, H_Pressed, H_Released;
	Event J, J_Pressed, J_Released;
	Event K, K_Pressed, K_Released;
	Event L, L_Pressed, L_Released;
	Event SemiColon, SemiColon_Pressed, SemiColon_Released;
	Event Apostrophe, Apostrophe_Pressed, Apostrophe_Released;
	Event Enter, Enter_Pressed, Enter_Released;
	Event LeftShift, LeftShift_Pressed, LeftShift_Released;
	Event Z, Z_Pressed, Z_Released;
	Event X, X_Pressed, X_Released;
	Event C, C_Pressed, C_Released;
	Event V, V_Pressed, V_Released;
	Event B, B_Pressed, B_Released;
	Event N, N_Pressed, N_Released;
	Event M, M_Pressed, M_Released;
	Event Comma, Comma_Pressed, Comma_Released;
	Event Period, Period_Pressed, Period_Released;
	Event ForwardSlash, ForwardSlash_Pressed, ForwardSlash_Released;
	Event RightShift, RightShift_Pressed, RightShift_Released;
	Event LeftControl, LeftControl_Pressed, LeftControl_Released;
	Event LeftAlt, LeftAlt_Pressed, LeftAlt_Released;
	Event Space, Space_Pressed, Space_Released;
	Event RightAlt, RightAlt_Pressed, RightAlt_Released;
	Event RightControl, RightControl_Pressed, RightControl_Released;
	Event Insert, Insert_Pressed, Insert_Released;
	Event Home, Home_Pressed, Home_Released;
	Event Delete, Delete_Pressed, Delete_Released;
	Event End, End_Pressed, End_Released;
	Event PageUp, PageUp_Pressed, PageUp_Released;
	Event PageDown, PageDown_Pressed, PageDown_Released;
	Event Up, Up_Pressed, Up_Released;
	Event Down, Down_Pressed, Down_Released;
	Event Left, Left_Pressed, Left_Released;
	Event Right, Right_Pressed, Right_Released;
	Event Divide, Divide_Pressed, Divide_Released;
	Event Multiply, Multiply_Pressed, Multiply_Released;
	Event Dash, Dash_Pressed, Dash_Released;
	Event Addition, Addition_Pressed, Addition_Released;
	Event Submit, Submit_Pressed, Submit_Released;
	Event Decimal, Decimal_Pressed, Decimal_Released;
	Event NumZero, NumZero_Pressed, NumZero_Released;
	Event NumOne, NumOne_Pressed, NumOne_Released;
	Event NumTwo, NumTwo_Pressed, NumTwo_Released;
	Event NumThree, NumThree_Pressed, NumThree_Released;
	Event NumFour, NumFour_Pressed, NumFour_Released;
	Event NumFive, NumFive_Pressed, NumFive_Released;
	Event NumSix, NumSix_Pressed, NumSix_Released;
	Event NumSeven, NumSeven_Pressed, NumSeven_Released;
	Event NumEight, NumEight_Pressed, NumEight_Released;
	Event NumNine, NumNine_Pressed, NumNine_Released;
	Event LeftClick, LeftClick_Pressed, LeftClick_Released;
	Event RightClick, RightClick_Pressed, RightClick_Released;
	MouseEvent MouseOffset;
	MouseEvent MousePosition;
	
#pragma endregion

private:
	InputManager();

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
#pragma endregion
};