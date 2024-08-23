#include "InputManager.h"

InputManager::InputManager()
{
}

//start the input manager
int InputManager::Start()
{
	return 0;
}

//free any data on the heap
int InputManager::Stop()
{
	return 0;
}

//singleton get function
InputManager& InputManager::getInstance()
{
	static InputManager single;
	return single;
}

//Input function for mouse movement
void InputManager::mouseMove(float posx, float posy)
{

}

//Process all key presses on the window and transfer them to Events
void InputManager::processInputs(GLFWwindow* window)
{
	//Long if statements handling the inputs from GLFW into the engine events
	if (glfwGetKey(window, GLFW_KEY_ESCAPE))
	{
		Escape.callEvent();
		if (Escape_bool == false)
		{
			Escape_Pressed.callEvent();
			Escape_bool = true;
		}
	}
	else if(Escape_bool == true)
	{
		Escape_Released.callEvent();
		Escape_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_F1))
	{
		F1.callEvent();
		if (F1_bool == false)
		{
			F1_Pressed.callEvent();
			F1_bool = true;
		}
	}
	else if (F1_bool == true)
	{
		F1_Released.callEvent();
		F1_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_F2))
	{
		F2.callEvent();
		if (F2_bool == false)
		{
			F2_Pressed.callEvent();
			F2_bool = true;
		}
	}
	else if (F2_bool == true)
	{
		F2_Released.callEvent();
		F2_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_F3))
	{
		F3.callEvent();
		if (F3_bool == false)
		{
			F3_Pressed.callEvent();
			F3_bool = true;
		}
	}
	else if (F3_bool == true)
	{
		F3_Released.callEvent();
		F3_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_F4))
	{
		F4.callEvent();
		if (F4_bool == false)
		{
			F4_Pressed.callEvent();
			F4_bool = true;
		}
	}
	else if (F4_bool == true)
	{
		F4_Released.callEvent();
		F4_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_F5))
	{
		F5.callEvent();
		if (F5_bool == false)
		{
			F5_Pressed.callEvent();
			F5_bool = true;
		}
	}
	else if (F5_bool == true)
	{
		F5_Released.callEvent();
		F5_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_F6))
	{
		F6.callEvent();
		if (F6_bool == false)
		{
			F6_Pressed.callEvent();
			F6_bool = true;
		}
	}
	else if (F6_bool == true)
	{
		F6_Released.callEvent();
		F6_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_F7))
	{
		F7.callEvent();
		if (F7_bool == false)
		{
			F7_Pressed.callEvent();
			F7_bool = true;
		}
	}
	else if (F7_bool == true)
	{
		F7_Released.callEvent();
		F7_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_F8))
	{
		F8.callEvent();
		if (F8_bool == false)
		{
			F8_Pressed.callEvent();
			F8_bool = true;
		}
	}
	else if (F8_bool == true)
	{
		F8_Released.callEvent();
		F8_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_F9))
	{
		F9.callEvent();
		if (F9_bool == false)
		{
			F9_Pressed.callEvent();
			F9_bool = true;
		}
	}
	else if (F9_bool == true)
	{
		F9_Released.callEvent();
		F9_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_F10))
	{
		F10.callEvent();
		if (F10_bool == false)
		{
			F10_Pressed.callEvent();
			F10_bool = true;
		}
	}
	else if (F10_bool == true)
	{
		F10_Released.callEvent();
		F10_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_F11))
	{
		F11.callEvent();
		if (F11_bool == false)
		{
			F11_Pressed.callEvent();
			F11_bool = true;
		}
	}
	else if (F11_bool == true)
	{
		F11_Released.callEvent();
		F11_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_F12))
	{
		F12.callEvent();
		if (F12_bool == false)
		{
			F12_Pressed.callEvent();
			F12_bool = true;
		}
	}
	else if (F12_bool == true)
	{
		F12_Released.callEvent();
		F12_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_MINUS))
	{
		Dash.callEvent();
		if (Dash_bool == false)
		{
			Dash_Pressed.callEvent();
			Dash_bool = true;
		}
	}
	else if (Dash_bool == true)
	{
		Dash_Released.callEvent();
		Dash_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_EQUAL))
	{
		Equals.callEvent();
		if (Equals_bool == false)
		{
			Equals_Pressed.callEvent();
			Equals_bool = true;
		}
	}
	else if (Equals_bool == true)
	{
		Equals_Released.callEvent();
		Equals_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_BACKSPACE))
	{
		Backspace.callEvent();
		if (Backspace_bool == false)
		{
			Backspace_Pressed.callEvent();
			Backspace_bool = true;
		}
	}
	else if (Backspace_bool == true)
	{
		Backspace_Released.callEvent();
		Backspace_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_TAB))
	{
		Tab.callEvent();
		if (Tab_bool == false)
		{
			Tab_Pressed.callEvent();
			Tab_bool = true;
		}
	}
	else if (Tab_bool == true)
	{
		Tab_Released.callEvent();
		Tab_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_Q))
	{
		Q.callEvent();
		if (Q_bool == false)
		{
			Q_Pressed.callEvent();
			Q_bool = true;
		}
	}
	else if (Q_bool == true)
	{
		Q_Released.callEvent();
		Q_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_W))
	{
		W.callEvent();
		if (W_bool == false)
		{
			W_Pressed.callEvent();
			W_bool = true;
		}
	}
	else if (W_bool == true)
	{
		W_Released.callEvent();
		W_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_E))
	{
		E.callEvent();
		if (E_bool == false)
		{
			E_Pressed.callEvent();
			E_bool = true;
		}
	}
	else if (E_bool == true)
	{
		E_Released.callEvent();
		E_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_R))
	{
		R.callEvent();
		if (R_bool == false)
		{
			R_Pressed.callEvent();
			R_bool = true;
		}
	}
	else if (R_bool == true)
	{
		R_Released.callEvent();
		R_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_T))
	{
		T.callEvent();
		if (T_bool == false)
		{
			T_Pressed.callEvent();
			T_bool = true;
		}
	}
	else if (T_bool == true)
	{
		T_Released.callEvent();
		T_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_Y))
	{
		Y.callEvent();
		if (Y_bool == false)
		{
			Y_Pressed.callEvent();
			Y_bool = true;
		}
	}
	else if (Y_bool == true)
	{
		Y_Released.callEvent();
		Y_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_U))
	{
		U.callEvent();
		if (U_bool == false)
		{
			U_Pressed.callEvent();
			U_bool = true;
		}
	}
	else if (U_bool == true)
	{
		U_Released.callEvent();
		U_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_I))
	{
		I.callEvent();
		if (I_bool == false)
		{
			I_Pressed.callEvent();
			I_bool = true;
		}
	}
	else if (I_bool == true)
	{
		I_Released.callEvent();
		I_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_O))
	{
		O.callEvent();
		if (O_bool == false)
		{
			O_Pressed.callEvent();
			O_bool = true;
		}
	}
	else if (O_bool == true)
	{
		O_Released.callEvent();
		O_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_P))
	{
		P.callEvent();
		if (P_bool == false)
		{
			P_Pressed.callEvent();
			P_bool = true;
		}
	}
	else if (P_bool == true)
	{
		P_Released.callEvent();
		P_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_BRACKET))
	{
		LeftBracket.callEvent();
		if (LeftBracket_bool == false)
		{
			LeftBracket_Pressed.callEvent();
			LeftBracket_bool = true;
		}
	}
	else if (LeftBracket_bool == true)
	{
		LeftBracket_Released.callEvent();
		LeftBracket_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT_BRACKET))
	{
		RightBracket.callEvent();
		if (RightBracket_bool == false)
		{
			RightBracket_Pressed.callEvent();
			RightBracket_bool = true;
		}
	}
	else if (RightBracket_bool == true)
	{
		RightBracket_Released.callEvent();
		RightBracket_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_BACKSLASH))
	{
		Backslash.callEvent();
		if (BackSlash_bool == false)
		{
			Backslash_Pressed.callEvent();
			BackSlash_bool = true;
		}
	}
	else if (BackSlash_bool == true)
	{
		Backslash_Released.callEvent();
		BackSlash_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_CAPS_LOCK))
	{
		Caps.callEvent();
		if (Caps_bool == false)
		{
			Caps_Pressed.callEvent();
			Caps_bool = true;
		}
	}
	else if (Caps_bool == true)
	{
		Caps_Released.callEvent();
		Caps_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_A))
	{
		A.callEvent();
		if (A_bool == false)
		{
			A_Pressed.callEvent();
			A_bool = true;
		}
	}
	else if (A_bool == true)
	{
		A_Released.callEvent();
		A_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_S))
	{
		S.callEvent();
		if (S_bool == false)
		{
			S_Pressed.callEvent();
			S_bool = true;
		}
	}
	else if (S_bool == true)
	{
		S_Released.callEvent();
		S_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_D))
	{
		D.callEvent();
		if (D_bool == false)
		{
			D_Pressed.callEvent();
			D_bool = true;
		}
	}
	else if (D_bool == true)
	{
		D_Released.callEvent();
		D_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_F))
	{
		F.callEvent();
		if (F_bool == false)
		{
			F_Pressed.callEvent();
			F_bool = true;
		}
	}
	else if (F_bool == true)
	{
		F_Released.callEvent();
		F_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_G))
	{
		G.callEvent();
		if (G_bool == false)
		{
			G_Pressed.callEvent();
			G_bool = true;
		}
	}
	else if (G_bool == true)
	{
		G_Released.callEvent();
		G_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_H))
	{
		H.callEvent();
		if (H_bool == false)
		{
			H_Pressed.callEvent();
			H_bool = true;
		}
	}
	else if (H_bool == true)
	{
		H_Released.callEvent();
		H_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_J))
	{
		J.callEvent();
		if (J_bool == false)
		{
			J_Pressed.callEvent();
			J_bool = true;
		}
	}
	else if (J_bool == true)
	{
		J_Released.callEvent();
		J_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_K))
	{
		K.callEvent();
		if (K_bool == false)
		{
			K_Pressed.callEvent();
			K_bool = true;
		}
	}
	else if (K_bool == true)
	{
		K_Released.callEvent();
		K_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_L))
	{
		L.callEvent();
		if (L_bool == false)
		{
			L_Pressed.callEvent();
			L_bool = true;
		}
	}
	else if (L_bool == true)
	{
		L_Released.callEvent();
		L_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_SEMICOLON))
	{
		SemiColon.callEvent();
		if (SemiColon_bool == false)
		{
			SemiColon_Pressed.callEvent();
			SemiColon_bool = true;
		}
	}
	else if (SemiColon_bool == true)
	{
		SemiColon_Released.callEvent();
		SemiColon_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_APOSTROPHE))
	{
		Apostrophe.callEvent();
		if (Apostrophe_bool == false)
		{
			Apostrophe_Pressed.callEvent();
			Apostrophe_bool = true;
		}
	}
	else if (Apostrophe_bool == true)
	{
		Apostrophe_Released.callEvent();
		Apostrophe_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_ENTER))
	{
		Enter.callEvent();
		if (Enter_bool == false)
		{
			Enter_Pressed.callEvent();
			Enter_bool = true;
		}
	}
	else if (Enter_bool == true)
	{
		Enter_Released.callEvent();
		Enter_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT))
	{
		LeftShift.callEvent();
		if (LeftShift_bool == false)
		{
			LeftShift_Pressed.callEvent();
			LeftShift_bool = true;
		}
	}
	else if (LeftShift_bool == true)
	{
		LeftShift_Released.callEvent();
		LeftShift_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_Z))
	{
		Z.callEvent();
		if (Z_bool == false)
		{
			Z_Pressed.callEvent();
			Z_bool = true;
		}
	}
	else if (Z_bool == true)
	{
		Z_Released.callEvent();
		Z_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_X))
	{
		X.callEvent();
		if (X_bool == false)
		{
			X_Pressed.callEvent();
			X_bool = true;
		}
	}
	else if (X_bool == true)
	{
		X_Released.callEvent();
		X_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_C))
	{
		C.callEvent();
		if (C_bool == false)
		{
			C_Pressed.callEvent();
			C_bool = true;
		}
	}
	else if (C_bool == true)
	{
		C_Released.callEvent();
		C_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_V))
	{
		V.callEvent();
		if (V_bool == false)
		{
			V_Pressed.callEvent();
			V_bool = true;
		}
	}
	else if (V_bool == true)
	{
		V_Released.callEvent();
		V_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_B))
	{
		B.callEvent();
		if (B_bool == false)
		{
			B_Pressed.callEvent();
			B_bool = true;
		}
	}
	else if (B_bool == true)
	{
		B_Released.callEvent();
		B_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_N))
	{
		N.callEvent();
		if (N_bool == false)
		{
			N_Pressed.callEvent();
			N_bool = true;
		}
	}
	else if (N_bool == true)
	{
		N_Released.callEvent();
		N_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_M))
	{
		M.callEvent();
		if (M_bool == false)
		{
			M_Pressed.callEvent();
			M_bool = true;
		}
	}
	else if (M_bool == true)
	{
		M_Released.callEvent();
		M_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_COMMA))
	{
		Comma.callEvent();
		if (Comma_bool == false)
		{
			Comma_Pressed.callEvent();
			Comma_bool = true;
		}
	}
	else if (Comma_bool == true)
	{
		Comma_Released.callEvent();
		Comma_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_PERIOD))
	{
		Period.callEvent();
		if (Period_bool == false)
		{
			Period_Pressed.callEvent();
			Period_bool = true;
		}
	}
	else if (Period_bool == true)
	{
		Period_Released.callEvent();
		Period_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_SLASH))
	{
		ForwardSlash.callEvent();
		if (ForwardSlash_bool == false)
		{
			ForwardSlash_Pressed.callEvent();
			ForwardSlash_bool = true;
		}
	}
	else if (ForwardSlash_bool == true)
	{
		ForwardSlash_Released.callEvent();
		ForwardSlash_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT))
	{
		RightShift.callEvent();
		if (RightShift_bool == false)
		{
			RightShift_Pressed.callEvent();
			RightShift_bool = true;
		}
	}
	else if (RightShift_bool == true)
	{
		RightShift_Released.callEvent();
		RightShift_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL))
	{
		LeftControl.callEvent();
		if (LeftControl_bool == false)
		{
			LeftControl_Pressed.callEvent();
			LeftControl_bool = true;
		}
	}
	else if (LeftControl_bool == true)
	{
		LeftControl_Released.callEvent();
		LeftControl_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_ALT))
	{
		LeftAlt.callEvent();
		if (LeftAlt_bool == false)
		{
			LeftAlt_Pressed.callEvent();
			LeftAlt_bool = true;
		}
	}
	else if (LeftAlt_bool == true)
	{
		LeftAlt_Released.callEvent();
		LeftAlt_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE))
	{
		Space.callEvent();
		if (Space_bool == false)
		{
			Space_Pressed.callEvent();
			Space_bool = true;
		}
	}
	else if (Space_bool == true)
	{
		Space_Released.callEvent();
		Space_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT_ALT))
	{
		RightAlt.callEvent();
		if (RightAlt_bool == false)
		{
			RightAlt_Pressed.callEvent();
			RightAlt_bool = true;
		}
	}
	else if (RightAlt_bool == true)
	{
		RightAlt_Released.callEvent();
		RightAlt_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL))
	{
		RightControl.callEvent();
		if (RightControl_bool == false)
		{
			RightControl_Pressed.callEvent();
			RightControl_bool = true;
		}
	}
	else if (RightControl_bool == true)
	{
		RightControl_Released.callEvent();
		RightControl_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_INSERT))
	{
		Insert.callEvent();
		if (Insert_bool == false)
		{
			Insert_Pressed.callEvent();
			Insert_bool = true;
		}
	}
	else if (Insert_bool == true)
	{
		Insert_Released.callEvent();
		Insert_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_HOME))
	{
		Home.callEvent();
		if (Home_bool == false)
		{
			Home_Pressed.callEvent();
			Home_bool = true;
		}
	}
	else if (Home_bool == true)
	{
		Home_Released.callEvent();
		Home_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_DELETE))
	{
		Delete.callEvent();
		if (Delete_bool == false)
		{
			Delete_Pressed.callEvent();
			Delete_bool = true;
		}
	}
	else if (Delete_bool == true)
	{
		Delete_Released.callEvent();
		Delete_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_END))
	{
		End.callEvent();
		if (End_bool == false)
		{
			End_Pressed.callEvent();
			End_bool = true;
		}
	}
	else if (End_bool == true)
	{
		End_Released.callEvent();
		End_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_PAGE_UP))
	{
		PageUp.callEvent();
		if (PageUp_bool == false)
		{
			PageUp_Pressed.callEvent();
			PageUp_bool = true;
		}
	}
	else if (PageUp_bool == true)
	{
		PageUp_Released.callEvent();
		PageUp_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_PAGE_DOWN))
	{
		PageDown.callEvent();
		if (PageDown_bool == false)
		{
			PageDown_Pressed.callEvent();
			PageDown_bool = true;
		}
	}
	else if (PageDown_bool == true)
	{
		PageDown_Released.callEvent();
		PageDown_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_KP_DIVIDE))
	{
		Divide.callEvent();
		if (Divide_bool == false)
		{
			Divide_Pressed.callEvent();
			Divide_bool = true;
		}
	}
	else if (Divide_bool == true)
	{
		Divide_Released.callEvent();
		Divide_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_KP_MULTIPLY))
	{
		Multiply.callEvent();
		if (Multiply_bool == false)
		{
			Multiply_Pressed.callEvent();
			Multiply_bool = true;
		}
	}
	else if (Multiply_bool == true)
	{
		Multiply_Released.callEvent();
		Multiply_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_KP_SUBTRACT))
	{
		Minus.callEvent();
		if (Minus_bool == false)
		{
			Minus_Pressed.callEvent();
			Minus_bool = true;
		}
	}
	else if (Minus_bool == true)
	{
		Minus_Released.callEvent();
		Minus_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_KP_ADD))
	{
		Addition.callEvent();
		if (Addition_bool == false)
		{
			Addition_Pressed.callEvent();
			Addition_bool = true;
		}
	}
	else if (Addition_bool == true)
	{
		Addition_Released.callEvent();
		Addition_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_KP_ENTER))
	{
		Submit.callEvent();
		if (Submit_bool == false)
		{
			Submit_Pressed.callEvent();
			Submit_bool = true;
		}
	}
	else if (Submit_bool == true)
	{
		Submit_Released.callEvent();
		Submit_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_KP_1))
	{
		NumOne.callEvent();
		if (NumOne_bool == false)
		{
			NumOne_Pressed.callEvent();
			NumOne_bool = true;
		}
	}
	else if (NumOne_bool == true)
	{
		NumOne_Released.callEvent();
		NumOne_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_KP_2))
	{
		NumTwo.callEvent();
		if (NumTwo_bool == false)
		{
			NumTwo_Pressed.callEvent();
			NumTwo_bool = true;
		}
	}
	else if (NumTwo_bool == true)
	{
		NumTwo_Released.callEvent();
		NumTwo_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_KP_3))
	{
		NumThree.callEvent();
		if (NumThree_bool == false)
		{
			NumThree_Pressed.callEvent();
			NumThree_bool = true;
		}
	}
	else if (NumThree_bool == true)
	{
		NumThree_Released.callEvent();
		NumThree_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_KP_4))
	{
		NumFour.callEvent();
		if (NumFour_bool == false)
		{
			NumFour_Pressed.callEvent();
			NumFour_bool = true;
		}
	}
	else if (NumFour_bool == true)
	{
		NumFour_Released.callEvent();
		NumFour_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_KP_5))
	{
		NumFive.callEvent();
		if (NumFive_bool == false)
		{
			NumFive_Pressed.callEvent();
			NumFive_bool = true;
		}
	}
	else if (NumFive_bool == true)
	{
		NumFive_Released.callEvent();
		NumFive_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_KP_6))
	{
		NumSix.callEvent();
		if (NumSix_bool == false)
		{
			NumSix_Pressed.callEvent();
			NumSix_bool = true;
		}
	}
	else if (NumSix_bool == true)
	{
		NumSix_Released.callEvent();
		NumSix_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_KP_7))
	{
		NumSeven.callEvent();
		if (NumSeven_bool == false)
		{
			NumSeven_Pressed.callEvent();
			NumSeven_bool = true;
		}
	}
	else if (NumSeven_bool == true)
	{
		NumSeven_Released.callEvent();
		NumSeven_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_KP_8))
	{
		NumEight.callEvent();
		if (NumEight_bool == false)
		{
			NumEight_Pressed.callEvent();
			NumEight_bool = true;
		}
	}
	else if (NumEight_bool == true)
	{
		NumEight_Released.callEvent();
		NumEight_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_KP_9))
	{
		NumNine.callEvent();
		if (NumNine_bool == false)
		{
			NumNine_Pressed.callEvent();
			NumNine_bool = true;
		}
	}
	else if (NumNine_bool == true)
	{
		NumNine_Released.callEvent();
		NumNine_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_KP_0))
	{
		NumZero.callEvent();
		if (NumZero_bool == false)
		{
			NumZero_Pressed.callEvent();
			NumZero_bool = true;
		}
	}
	else if (NumZero_bool == true)
	{
		NumZero_Released.callEvent();
		NumZero_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_KP_DECIMAL))
	{
		Decimal.callEvent();
		if (Decimal_bool == false)
		{
			Decimal_Pressed.callEvent();
			Decimal_bool = true;
		}
	}
	else if (Decimal_bool == true)
	{
		Decimal_Released.callEvent();
		Decimal_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_UP))
	{
		Up.callEvent();
		if (Up_bool == false)
		{
			Up_Pressed.callEvent();
			Up_bool = true;
		}
	}
	else if (Up_bool == true)
	{
		Up_Released.callEvent();
		Up_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT))
	{
		Left.callEvent();
		if (Left_bool == false)
		{
			Left_Pressed.callEvent();
			Left_bool = true;
		}
	}
	else if (Left_bool == true)
	{
		Left_Released.callEvent();
		Left_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN))
	{
		Down.callEvent();
		if (Down_bool == false)
		{
			Down_Pressed.callEvent();
			Down_bool = true;
		}
	}
	else if (Down_bool == true)
	{
		Down_Released.callEvent();
		Down_bool = false;
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT))
	{
		Right.callEvent();
		if (Right_bool == false)
		{
			Right_Pressed.callEvent();
			Right_bool = true;
		}
	}
	else if (Right_bool == true)
	{
		Right_Released.callEvent();
		Right_bool = false;
	}
}