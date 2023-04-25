/*
	NOTE:
	This file was autogenerated by CppGen, changes may be overwritten and forever lost!
	Modify at your own risk!
	
	[ Generated on 2023.04.25 00:08:41 ]
*/

#include "Scripts.hpp"

namespace CppProject
{
	VarType history_set_var(ScopeAny self, IntType script, VarType oldval, VarType newval, RealType combine)
	{
		VarType hobj;
		history_pop(self);
		if (combine > 0 && sReal(history_amount) > IntType(0) && ObjType(obj_history, sArr(history).Value(IntType(0)))->script == script && ObjType(obj_history, sArr(history).Value(IntType(0)))->save_temp_edit == save_id_get(global::temp_edit) && ObjType(obj_history, sArr(history).Value(IntType(0)))->save_axis_edit == global::axis_edit)
			hobj = sArr(history).Value(IntType(0));
		else
		{
			history_push(self);
			log({ /*"Action Set variable"*/ STR(1199), script_get_name(script), oldval, newval, combine });
			hobj = new_history(script);
			ObjType(obj_history, hobj)->old_value = oldval;
			ObjType(obj_history, hobj)->save_set_var = true;
			sArr(history)[IntType(0)] = hobj;
		}
		
		ObjType(obj_history, hobj)->new_value = newval;
		return hobj;
	}
	
	void history_startup()
	{
		global::_app->history[IntType(0)] = null_;
		global::_app->history_amount = IntType(0);
		global::_app->history_pos = IntType(0);
		global::_app->history_undo = IntType(0);
		global::_app->history_redo = IntType(0);
		global::_app->history_resource_update = false;
		global::history_data = null_;
	}
	
	IntType history_undo_res()
	{
		if (ObjType(obj_history, global::history_data)->filename != /*""*/ STR(0) && (!ObjType(obj_history, global::history_data)->replaced || ObjType(obj_history, global::history_data)->copied))
		{
			withOne (Object, save_id_find(ObjType(obj_history, global::history_data)->new_res_save_id), noone)
			{
				file_delete_lib(global::_app->project_folder + /*"/"*/ STR(16) + sVar(filename));
				instance_destroy(self);
			}
			
		}
		return save_id_find(ObjType(obj_history, global::history_data)->old_res_save_id);
	}
	
	void interface_update_accent()
	{
		global::c_accent_hover = merge_color((IntType)(global::c_accent), c_white, .2);
		global::c_accent_pressed = merge_color((IntType)(global::c_accent), c_black, .2);
		global::c_accent_overlay = global::c_accent;
		global::c_hover = global::c_accent;
	}
	
	void interface_update_instant(ScopeAny self)
	{
		IntType theme = sInt(setting_theme);
		global::c_text_main = ObjType(obj_theme, theme)->text_main;
		global::c_text_secondary = ObjType(obj_theme, theme)->text_secondary;
		global::c_text_tertiary = ObjType(obj_theme, theme)->text_tertiary;
		global::c_border = ObjType(obj_theme, theme)->border;
		global::c_overlay = ObjType(obj_theme, theme)->overlay;
		global::c_button_text = ObjType(obj_theme, theme)->button_text;
		global::a_button_text = ObjType(obj_theme, theme)->button_text_alpha;
		global::a_dark_overlay = ObjType(obj_theme, theme)->dark_overlay_alpha;
		global::c_level_top = ObjType(obj_theme, theme)->level_top;
		global::c_level_middle = ObjType(obj_theme, theme)->level_middle;
		global::c_level_bottom = ObjType(obj_theme, theme)->level_bottom;
		global::c_viewport_top = ObjType(obj_theme, theme)->viewport_top;
		global::c_viewport_bottom = ObjType(obj_theme, theme)->viewport_bottom;
		global::c_error = ObjType(obj_theme, theme)->red_error;
		global::c_warning = ObjType(obj_theme, theme)->yellow_warning;
		global::c_success = ObjType(obj_theme, theme)->green_success;
		global::c_axisred = ObjType(obj_theme, theme)->red;
		global::c_axisgreen = ObjType(obj_theme, theme)->green;
		global::c_axisblue = ObjType(obj_theme, theme)->blue;
		global::c_bend = ObjType(obj_theme, theme)->pink;
		global::c_axiscyan = ObjType(obj_theme, theme)->cyan;
		global::c_axisyellow = ObjType(obj_theme, theme)->yellow;
		global::c_axismagenta = ObjType(obj_theme, theme)->magenta;
		if (sInt(setting_accent) == IntType(9))
			global::c_accent = sVar(setting_accent_custom);
		else
			global::c_accent = ObjType(obj_theme, theme)->accent_list.Value(sInt(setting_accent));
		
		interface_update_accent();
	}
	
	VarType json_file_convert_unicode(VarType src, StringType dest)
	{
		return lib_json_file_convert_unicode(src, dest);
	}
	
	BoolType json_load_array()
	{
		IntType list = ds_list_create();
		while (json_load_char())
		{
			if (global::json_char == e_json_char_SQUARE_END)
				break;
			if (!json_load_value())
				break;
			ds_list_add({ list, global::json_value });
			switch ((IntType)global::json_value_type)
			{
				case e_json_type_OBJECT:
				{
					ds_list_mark_as_map(list, (IntType)(ds_list_size(list) - IntType(1)));
					break;
				}
				case e_json_type_ARRAY:
				{
					ds_list_mark_as_list(list, (IntType)(ds_list_size(list) - IntType(1)));
					break;
				}
			}
			
			if (global::json_char == e_json_char_SQUARE_END)
				break;
			if (global::json_char != e_json_char_COMMA)
			{
				global::json_error = /*"Expected \",\""*/ STR(1204);
				break;
			}
		}
		
		if (global::json_error != /*""*/ STR(0))
		{
			ds_list_destroy(list);
			return false;
		}
		global::json_value = list;
		global::json_value_type = e_json_type_ARRAY;
		json_load_char();
		return true;
	}
	
	BoolType json_load_char()
	{
		if (buffer_is_eof())
		{
			global::json_error = /*"Unexpected end of file"*/ STR(1205);
			return false;
		}
		do
		{
			global::json_char = buffer_read_byte();
			if (global::json_char == e_json_char_TAB)
				global::json_column += IntType(4);
			else
				if (global::json_char == e_json_char_NEW_LINE)
				{
					global::json_line++;
					global::json_column = IntType(0);
				}
				else
					global::json_column++;
			
			
		}
		while (!(global::json_char != e_json_char_TAB && global::json_char != e_json_char_SPACE && global::json_char != e_json_char_NEW_LINE && global::json_char != e_json_char_RETURN && global::json_char < IntType(127)));
		return true;
	}
	
	BoolType json_load_number()
	{
		StringType str, ex;
		BoolType expart;
		str = /*""*/ STR(0);
		expart = false;
		ex = /*""*/ STR(0);
		do
		{
			if (!expart)
				str += chr(global::json_char);
			else
				ex += chr(global::json_char);
			
			global::json_char = buffer_read_byte();
			global::json_column++;
			if (buffer_is_eof())
			{
				global::json_error = /*"Unexpected end of file"*/ STR(1205);
				return false;
			}
			if (global::json_char == e_json_char_E || global::json_char == e_json_char_CAPITAL_E)
			{
				if (expart)
				{
					global::json_error = /*"Unexpected symbol"*/ STR(1206);
					return false;
				}
				global::json_char = buffer_read_byte();
				global::json_column++;
				if (buffer_is_eof())
				{
					global::json_error = /*"Unexpected end of file"*/ STR(1205);
					return false;
				}
				expart = true;
			}
		}
		while (!((global::json_char < e_json_char_NUM_0 || global::json_char > e_json_char_NUM_9) && global::json_char != e_json_char_POINT && global::json_char != e_json_char_MINUS && global::json_char != e_json_char_PLUS));
		if (global::json_char == e_json_char_TAB || global::json_char == e_json_char_SPACE || global::json_char == e_json_char_NEW_LINE || global::json_char == e_json_char_RETURN)
		{
			if (!json_load_char())
				return false;
		}
		global::json_value = string_get_real(str);
		global::json_value_type = e_json_type_NUMBER;
		if (expart)
			global::json_value = power(global::json_value, string_get_real(ex));
		if (is_undefined(global::json_value))
		{
			global::json_error = /*"Invalid number \""*/ STR(1207) + str + /*"\""*/ STR(1116);
			return false;
		}
		return true;
	}
	
	BoolType json_load_object(BoolType root)
	{
		IntType map = ds_map_create();
		if (global::json_type_map != null_)
			ds_map_add_map((IntType)(global::json_type_map), map, ds_map_create());
		while (json_load_char())
		{
			if (global::json_char == e_json_char_CURLY_END)
				break;
			if (!json_load_string())
				break;
			VarType name = global::json_value;
			if (global::json_char != e_json_char_COLON)
			{
				global::json_error = /*"Expected \":\""*/ STR(1208);
				break;
			}
			if (!json_load_char())
				break;
			if (!json_load_value())
				break;
			switch ((IntType)global::json_value_type)
			{
				case e_json_type_OBJECT:
				{
					ds_map_add_map(map, name, (IntType)(global::json_value));
					break;
				}
				case e_json_type_ARRAY:
				{
					ds_map_add_list(map, name, (IntType)(global::json_value));
					break;
				}
				default:
					DsMap(map)[name] = global::json_value;
			}
			
			if (global::json_type_map != null_)
				ds_map_add(DsMap(global::json_type_map).Value(map), name, global::json_value_type);
			if (global::json_char == e_json_char_CURLY_END)
				break;
			if (global::json_char != e_json_char_COMMA)
			{
				global::json_error = /*"Expected \",\""*/ STR(1204);
				break;
			}
		}
		
		if (!root)
			json_load_char();
		if (global::json_error != /*""*/ STR(0))
		{
			ds_map_destroy(map);
			return false;
		}
		global::json_value = map;
		global::json_value_type = e_json_type_OBJECT;
		return true;
	}
	
	BoolType json_load_string()
	{
		StringType str = /*""*/ STR(0);
		while (true)
		{
			if (buffer_is_eof())
			{
				global::json_error = /*"Unexpected end of file"*/ STR(1205);
				return false;
			}
			global::json_char = buffer_read_byte();
			global::json_column++;
			if (global::json_char == e_json_char_QUOTE)
				break;
			if (global::json_char == e_json_char_RETURN || global::json_char == e_json_char_NEW_LINE)
			{
				global::json_error = /*"Unexpected linebreak in string"*/ STR(1209);
				return false;
			}
			if (global::json_char == e_json_char_BACKSLASH)
			{
				if (buffer_is_eof())
				{
					global::json_error = /*"Unexpected end of file"*/ STR(1205);
					return false;
				}
				global::json_char = buffer_read_byte();
				global::json_column++;
				if (global::json_char == e_json_char_QUOTE)
					str += /*"\""*/ STR(1116);
				else
					if (global::json_char == e_json_char_BACKSLASH)
						str += /*"\\"*/ STR(1114);
					else
						if (global::json_char == e_json_char_N)
							str += /*"\n"*/ STR(952);
						else
							if (global::json_char == e_json_char_T)
								str += /*"\t"*/ STR(1024);
							else
								if (global::json_char == e_json_char_U)
								{
									StringType hex = /*""*/ STR(0);
									for (IntType _it = 0, _it_max = IntType(4); _it < _it_max; _it++)
									{
										if (buffer_is_eof())
										{
											global::json_error = /*"Unexpected end of file"*/ STR(1205);
											return false;
										}
										global::json_char = buffer_read_byte();
										global::json_column++;
										hex += chr(global::json_char);
									}
									str += chr((IntType)(hex_to_dec(hex)));
								}
								else
									str += chr(global::json_char);
							
						
					
				
				
			}
			else
				str += chr(global::json_char);
			
		}
		
		if (!json_load_char())
			return false;
		global::json_value = str;
		global::json_value_type = e_json_type_STRING;
		return true;
	}
	
	BoolType json_load_value()
	{
		if (global::json_char == e_json_char_CURLY_BEGIN)
			return json_load_object(false);
		else
			if (global::json_char == e_json_char_SQUARE_BEGIN)
				return json_load_array();
			else
				if (global::json_char == e_json_char_QUOTE)
					return json_load_string();
				else
					if ((global::json_char >= e_json_char_NUM_0 && global::json_char <= e_json_char_NUM_9) || global::json_char == e_json_char_MINUS)
						return json_load_number();
					else
						return json_load_word();
				
			
		
		
		return false;
	}
	
	BoolType json_load_word()
	{
		if (global::json_char == e_json_char_T)
		{
			for (IntType _it = 0, _it_max = IntType(4); _it < _it_max; _it++)
				if (!json_load_char())
					return false;
			global::json_value = true;
			global::json_value_type = e_json_type_BOOL;
		}
		else
			if (global::json_char == e_json_char_F)
			{
				for (IntType _it = 0, _it_max = IntType(5); _it < _it_max; _it++)
					if (!json_load_char())
						return false;
				global::json_value = false;
				global::json_value_type = e_json_type_BOOL;
			}
			else
				if (global::json_char == e_json_char_N)
				{
					for (IntType _it = 0, _it_max = IntType(4); _it < _it_max; _it++)
						if (!json_load_char())
							return false;
					global::json_value = null_;
					global::json_value_type = e_json_type_NULL_;
				}
				else
				{
					global::json_error = /*"Unrecognized word"*/ STR(1210);
					return false;
				}
			
		
		
		return true;
	}
	
	void json_save_array(VarType arr, IntType size)
	{
		buffer_write_byte(e_json_char_SQUARE_BEGIN);
		buffer_write_byte(e_json_char_SPACE);
		for (IntType i = IntType(0); i < size; i++)
		{
			if (i > IntType(0))
			{
				buffer_write_byte(e_json_char_COMMA);
				buffer_write_byte(e_json_char_SPACE);
			}
			json_save_value(arr.Value(i));
		}
		buffer_write_byte(e_json_char_SPACE);
		buffer_write_byte(e_json_char_SQUARE_END);
	}
	
	void json_save_array_done()
	{
		buffer_write_byte(e_json_char_RETURN);
		buffer_write_byte(e_json_char_NEW_LINE);
		global::json_indent--;
		json_save_indent();
		buffer_write_byte(e_json_char_SQUARE_END);
		global::json_add_comma = true;
	}
	
	void json_save_array_start(VarArgs argument)
	{
		IntType argument_count = argument.Size();
		if (global::json_add_comma)
			buffer_write_byte(e_json_char_COMMA);
		buffer_write_byte(e_json_char_RETURN);
		buffer_write_byte(e_json_char_NEW_LINE);
		json_save_indent();
		if (argument_count > IntType(0))
		{
			buffer_write_byte(e_json_char_QUOTE);
			buffer_write_string(argument[IntType(0)]);
			buffer_write_byte(e_json_char_QUOTE);
			buffer_write_byte(e_json_char_COLON);
			buffer_write_byte(e_json_char_SPACE);
		}
		buffer_write_byte(e_json_char_SQUARE_BEGIN);
		global::json_indent++;
		global::json_add_comma = false;
	}
	
	void json_save_array_value(VarType val)
	{
		if (global::json_add_comma)
			buffer_write_byte(e_json_char_COMMA);
		buffer_write_byte(e_json_char_RETURN);
		buffer_write_byte(e_json_char_NEW_LINE);
		json_save_indent();
		json_save_value(val);
		global::json_add_comma = true;
	}
	
	void json_save_done()
	{
		buffer_resize(global::buffer_current, buffer_tell(global::buffer_current));
		buffer_save_lib(global::buffer_current, global::json_filename);
		buffer_delete(global::buffer_current);
	}
	
	void json_save_indent()
	{
		for (IntType _it = 0, _it_max = global::json_indent; _it < _it_max; _it++)
			buffer_write_byte(e_json_char_TAB);
	}
	
	void json_save_object_done()
	{
		buffer_write_byte(e_json_char_RETURN);
		buffer_write_byte(e_json_char_NEW_LINE);
		global::json_indent--;
		json_save_indent();
		buffer_write_byte(e_json_char_CURLY_END);
		global::json_add_comma = true;
	}
	
	void json_save_object_start(VarArgs argument)
	{
		IntType argument_count = argument.Size();
		if (global::json_add_comma)
			buffer_write_byte(e_json_char_COMMA);
		if (!global::json_empty)
		{
			buffer_write_byte(e_json_char_RETURN);
			buffer_write_byte(e_json_char_NEW_LINE);
		}
		else
			global::json_empty = false;
		
		json_save_indent();
		if (argument_count > IntType(0))
		{
			buffer_write_byte(e_json_char_QUOTE);
			buffer_write_string(argument[IntType(0)]);
			buffer_write_byte(e_json_char_QUOTE);
			buffer_write_byte(e_json_char_COLON);
			buffer_write_byte(e_json_char_SPACE);
		}
		buffer_write_byte(e_json_char_CURLY_BEGIN);
		global::json_indent++;
		global::json_add_comma = false;
	}
	
	void json_save_start(VarType fn)
	{
		global::json_filename = fn;
		global::json_indent = IntType(0);
		global::json_empty = true;
		global::json_add_comma = false;
		global::buffer_current = buffer_create(IntType(8), buffer_grow, IntType(1));
	}
	
	void json_save_value(VarType val)
	{
		if (is_real(val) || is_int32(val) || is_int64(val))
			buffer_write_string(string_decimals(val));
		else
			if (is_array(val))
				json_save_array(val, array_length(VarType::CreateRef(val)));
			else
				if (is_bool(val))
					buffer_write_string(string(val));
				else
				{
					buffer_write_byte(e_json_char_QUOTE);
					buffer_write_string(val);
					buffer_write_byte(e_json_char_QUOTE);
				}
			
		
		
	}
	
	void json_save_var(VarType name, VarType val)
	{
		if (global::json_add_comma)
			buffer_write_byte(e_json_char_COMMA);
		buffer_write_byte(e_json_char_RETURN);
		buffer_write_byte(e_json_char_NEW_LINE);
		json_save_indent();
		buffer_write_byte(e_json_char_QUOTE);
		buffer_write_string(name);
		buffer_write_byte(e_json_char_QUOTE);
		buffer_write_byte(e_json_char_COLON);
		buffer_write_byte(e_json_char_SPACE);
		json_save_value(val);
		global::json_add_comma = true;
	}
	
	void json_save_var_bool(VarType name, VarType val)
	{
		if (global::json_add_comma)
			buffer_write_byte(e_json_char_COMMA);
		buffer_write_byte(e_json_char_RETURN);
		buffer_write_byte(e_json_char_NEW_LINE);
		json_save_indent();
		buffer_write_byte(e_json_char_QUOTE);
		buffer_write_string(name);
		buffer_write_byte(e_json_char_QUOTE);
		buffer_write_byte(e_json_char_COLON);
		buffer_write_byte(e_json_char_SPACE);
		buffer_write_string((val > 0) ? /*"true"*/ STR(760) : /*"false"*/ STR(761));
		global::json_add_comma = true;
	}
	
	void json_save_var_color(VarType name, VarType val)
	{
		if (global::json_add_comma)
			buffer_write_byte(e_json_char_COMMA);
		buffer_write_byte(e_json_char_RETURN);
		buffer_write_byte(e_json_char_NEW_LINE);
		json_save_indent();
		buffer_write_byte(e_json_char_QUOTE);
		buffer_write_string(name);
		buffer_write_byte(e_json_char_QUOTE);
		buffer_write_byte(e_json_char_COLON);
		buffer_write_byte(e_json_char_SPACE);
		json_save_value(/*"#"*/ STR(842) + color_to_hex(val));
		global::json_add_comma = true;
	}
	
	void json_save_var_nullable(StringType name, VarType val)
	{
		if (global::json_add_comma)
			buffer_write_byte(e_json_char_COMMA);
		buffer_write_byte(e_json_char_RETURN);
		buffer_write_byte(e_json_char_NEW_LINE);
		json_save_indent();
		buffer_write_byte(e_json_char_QUOTE);
		buffer_write_string(name);
		buffer_write_byte(e_json_char_QUOTE);
		buffer_write_byte(e_json_char_COLON);
		buffer_write_byte(e_json_char_SPACE);
		if (val == null_)
			json_save_value(/*"null"*/ STR(1211));
		else
			json_save_value(val);
		
		global::json_add_comma = true;
	}
	
	void json_save_var_point2D(StringType name, VarType value)
	{
		if (global::json_add_comma)
			buffer_write_byte(e_json_char_COMMA);
		buffer_write_byte(e_json_char_RETURN);
		buffer_write_byte(e_json_char_NEW_LINE);
		json_save_indent();
		buffer_write_byte(e_json_char_QUOTE);
		buffer_write_string(name);
		buffer_write_byte(e_json_char_QUOTE);
		buffer_write_byte(e_json_char_COLON);
		buffer_write_byte(e_json_char_SPACE);
		if (value == null_)
			json_save_value(/*"null"*/ STR(1211));
		else
			json_save_value(point2D(value.Value(X_), value.Value(Y_)));
		
		global::json_add_comma = true;
	}
	
	void json_save_var_point3D(StringType name, VarType value)
	{
		if (global::json_add_comma)
			buffer_write_byte(e_json_char_COMMA);
		buffer_write_byte(e_json_char_RETURN);
		buffer_write_byte(e_json_char_NEW_LINE);
		json_save_indent();
		buffer_write_byte(e_json_char_QUOTE);
		buffer_write_string(name);
		buffer_write_byte(e_json_char_QUOTE);
		buffer_write_byte(e_json_char_COLON);
		buffer_write_byte(e_json_char_SPACE);
		if (value == null_)
			json_save_value(/*"null"*/ STR(1211));
		else
			json_save_value(point3D(value.Value(X_), value.Value(Z_), value.Value(Y_)));
		
		global::json_add_comma = true;
	}
	
	void json_save_var_save_id(StringType name, VarType obj)
	{
		if (global::json_add_comma)
			buffer_write_byte(e_json_char_COMMA);
		buffer_write_byte(e_json_char_RETURN);
		buffer_write_byte(e_json_char_NEW_LINE);
		json_save_indent();
		buffer_write_byte(e_json_char_QUOTE);
		buffer_write_string(name);
		buffer_write_byte(e_json_char_QUOTE);
		buffer_write_byte(e_json_char_COLON);
		buffer_write_byte(e_json_char_SPACE);
		if (obj == null_)
			json_save_value(/*"null"*/ STR(1211));
		else
		{
			json_save_value(save_id_get(obj));
			idBool(obj, save) = true;
		}
		
		global::json_add_comma = true;
	}
	
	void json_save_var_state_vars(StringType name, VarType vars)
	{
		json_save_object_start({ name });
		for (IntType i = IntType(0); i < array_length(VarType::CreateRef(vars)); i += IntType(2))
			json_save_var(vars.Value(i), vars.Value(i + IntType(1)));
		json_save_object_done();
	}
	
	void json_startup()
	{
	}
	
	void keybinds_reset_default(ScopeAny self)
	{
		for (IntType i = IntType(0); i < e_keybind_amount; i++)
			keybind_restore(self, i, true);
		keybinds_update_match();
		settings_save(self);
	}
	
	void keybinds_update_match()
	{
		withAll (obj_keybind, noone)
		{
			self->match_error = false;
			withAll (obj_keybind, self->id)
			{
				if (self->id == self.otherId)
					continue;
				if (array_equals(VarType::CreateRef(self->keybind), VarType::CreateRef(ObjType(obj_keybind, self.otherId)->keybind)) && (self->navigation == ObjType(obj_keybind, self.otherId)->navigation))
				{
					ObjType(obj_keybind, self.otherId)->match_error = true;
					break;
				}
			}
			
		}
		
	}
	
	BoolType keybind_check(VarType keybindobj, StringType checkscript)
	{
		VarType keybind;
		BoolType scriptres, charcheck;
		keybind = idVar(keybindobj, keybind);
		switch (StringType(checkscript).id)
		{
			case 690: // keyboard_check
			{
				scriptres = keyboard_check((IntType)(keybind.Value(e_keybind_key_CHAR)));
				break;
			}
			case 692: // keyboard_check_pressed
			{
				scriptres = keyboard_check_pressed((IntType)(keybind.Value(e_keybind_key_CHAR)));
				break;
			}
			case 691: // keyboard_check_released
			{
				scriptres = keyboard_check_released((IntType)(keybind.Value(e_keybind_key_CHAR)));
				break;
			}
		}
		
		charcheck = (keybind.Value(e_keybind_key_CHAR) == null_ || scriptres);
		if (checkscript == /*"keyboard_check"*/ STR(690))
		{
			idBool(keybindobj, check_ctrl) = (keyboard_check(vk_control) == keybind.Value(e_keybind_key_CTRL)) || (idBool(keybindobj, navigation) && !(keybind.Value(e_keybind_key_CTRL) > 0));
			idBool(keybindobj, check_shift) = (keyboard_check(vk_shift) == keybind.Value(e_keybind_key_SHIFT)) || (idBool(keybindobj, navigation) && !(keybind.Value(e_keybind_key_SHIFT) > 0));
			idBool(keybindobj, check_alt) = (keyboard_check(vk_alt) == keybind.Value(e_keybind_key_ALT)) || (idBool(keybindobj, navigation) && !(keybind.Value(e_keybind_key_ALT) > 0));
		}
		return (charcheck && idBool(keybindobj, check_ctrl) && idBool(keybindobj, check_shift) && idBool(keybindobj, check_alt));
	}
	
	void keybind_event_create(Scope<obj_keybind> self)
	{
		self->name = /*""*/ STR(0);
		self->keybind_id = null_;
		self->keybind = null_;
		self->keybind_default = null_;
		self->pressed = false;
		self->active = false;
		self->released = false;
		self->check_ctrl = false;
		self->check_shift = false;
		self->check_alt = false;
		self->match_error = false;
	}
	
	VarType keybind_new(VarType char_, BoolType ctrl, BoolType shift, BoolType alt)
	{
		if (is_string(char_))
			char_ = ord(char_);
		return ArrType::From({ char_, ctrl, shift, alt });
	}
	
	void keybind_register(StringType name, IntType keybindID, VarType keybind, BoolType navigation)
	{
		IntType obj = (new obj_keybind)->id;
		ObjType(obj_keybind, obj)->name = name;
		ObjType(obj_keybind, obj)->keybind_id = keybindID;
		ObjType(obj_keybind, obj)->keybind_default = keybind;
		ObjType(obj_keybind, obj)->keybind = keybind;
		ObjType(obj_keybind, obj)->navigation = navigation;
		global::keybinds[keybindID] = obj;
	}
	
	void keybind_restore(ScopeAny self, IntType keybindID, BoolType group)
	{
		VarType obj = global::keybinds.Value(keybindID);
		idVar(obj, keybind) = idVar(obj, keybind_default);
		if (!group)
		{
			keybinds_update_match();
			settings_save(self);
		}
	}
	
	void keybind_set(ScopeAny self, IntType keybindID, VarType keybind)
	{
		VarType obj = global::keybinds.Value(keybindID);
		idVar(obj, keybind) = keybind;
		keybinds_update_match();
		settings_save(self);
	}
	
	RealType keyframes_save(ScopeAny self)
	{
		BoolType ismodel;
		VarType tllast;
		ismodel = false;
		tllast = null_;
		withAll (obj_keyframe, self->id)
		{
			if (!(self->selected > 0))
				continue;
			if (tllast != null_ && self->timeline != tllast)
				ismodel = true;
			tllast = self->timeline;
		}
		
		VarType name;
		if (ismodel && idVar(global::tl_edit, part_of) != null_)
			name = idVar(idVar(global::tl_edit, part_of), display_name);
		else
			name = idVar(global::tl_edit, display_name);
		
		VarType fn = file_dialog_save_keyframes(name);
		if (fn == /*""*/ STR(0))
			return IntType(0);
		fn = filename_new_ext(fn, /*".miframes"*/ STR(33));
		log({ /*"Saving keyframes"*/ STR(1226), fn });
		global::save_folder = filename_dir(fn);
		global::load_folder = sStr(project_folder);
		log({ /*"load_folder"*/ STR(729), global::load_folder });
		log({ /*"save_folder"*/ STR(728), global::save_folder });
		project_save_start(fn, false);
		VarType firstpos, lastpos;
		firstpos = null_;
		lastpos = null_;
		withAll (obj_keyframe, self->id)
		{
			if (!(self->selected > 0))
				continue;
			tl_keyframe_save(self->id);
			if (firstpos == null_ || self->position < firstpos)
				firstpos = self->position;
			lastpos = max({ self->position, lastpos });
		}
		
		json_save_var_bool(/*"is_model"*/ STR(36), ismodel);
		json_save_var(/*"tempo"*/ STR(37), sVar(project_tempo));
		json_save_var(/*"length"*/ STR(39), lastpos - firstpos);
		json_save_array_start({ /*"keyframes"*/ STR(38) });
		withAll (obj_keyframe, self->id)
		{
			if (!(self->selected > 0))
				continue;
			json_save_object_start();
			json_save_var(/*"position"*/ STR(40), self->position - firstpos);
			if (ismodel && idVar(self->timeline, part_of) != null_)
				json_save_var(/*"part_name"*/ STR(41), idVar(self->timeline, model_part_name));
			keyframe_update_item_name(self);
			project_save_values(/*"values"*/ STR(42), self->value, idArr(self->timeline, value_default));
			json_save_object_done();
		}
		
		json_save_array_done();
		project_save_objects(self);
		project_save_done();
		log({ /*"Keyframes saved"*/ STR(1227) });
		return 0.0;
	}
	
	void keyframe_event_destroy(Scope<obj_keyframe> self)
	{
		ds_list_delete_value(idInt(self->timeline, keyframe_list), self->id);
		if (self->value.Value(e_value_SOUND_OBJ) != null_)
			idInt(self->value.Value(e_value_SOUND_OBJ), count)--;
	}
	
	RealType keyframe_update_item_name(Scope<obj_keyframe> self)
	{
		if (idVar(self->timeline, type) != e_tl_type_ITEM)
			return IntType(0);
		VarType slot = self->value.Value(e_value_ITEM_SLOT);
		if (self->value.Value(e_value_TEXTURE_OBJ) != null_)
		{
			VarType tex = self->value.Value(e_value_TEXTURE_OBJ);
			if (idVar(tex, type) == e_res_type_PACK && slot < ds_list_size((IntType)(ObjType(obj_minecraft_assets, global::mc_assets)->item_texture_list)))
				self->value[e_value_ITEM_NAME] = DsList(ObjType(obj_minecraft_assets, global::mc_assets)->item_texture_list).Value(slot);
			else
				self->value[e_value_ITEM_NAME] = /*""*/ STR(0);
			
		}
		else
			if (idVar(idVar(idVar(self->timeline, temp), item_tex), type) == e_res_type_PACK && slot < ds_list_size((IntType)(ObjType(obj_minecraft_assets, global::mc_assets)->item_texture_list)))
			{
				self->value[e_value_ITEM_NAME] = DsList(ObjType(obj_minecraft_assets, global::mc_assets)->item_texture_list).Value(slot);
			}
			else
				self->value[e_value_ITEM_NAME] = /*""*/ STR(0);
		
		
		return 0.0;
	}
	
	BoolType key_valid(VarType key)
	{
		StringType keystr;
		key = string_upper(key);
		keystr = /*"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"*/ STR(1228);
		if (string_length(key) != IntType(8))
			return false;
		for (IntType c = IntType(0); c < IntType(8); c += IntType(2))
		{
			IntType pos1, pos2;
			pos1 = string_pos(string_char_at(key, c + IntType(1)), keystr);
			pos2 = string_pos(string_char_at(key, (IntType)(IntType(8) - c)), keystr);
			if (pos1 == IntType(0) || pos2 == IntType(0))
				return false;
			if (pos1 != string_length(keystr) + IntType(1) - pos2)
				return false;
		}
		return true;
	}
	
	void langauge_new(StringType fn)
	{
		IntType obj = (new obj_language)->id;
		withOne (obj_language, obj, noone)
		{
			self->filename = filename_name(fn);
			self->name = text_get({ /*"filelanguage"*/ STR(1229) });
			self->locale = text_exists(/*"filelocale"*/ STR(1230)) ? string(text_get({ /*"filelocale"*/ STR(1230) })) : /*""*/ STR(0);
		}
		
	}
	
	RealType languages_load()
	{
		StringType fn = languages_file;
		if (!file_exists_lib(fn))
			return IntType(0);
		log({ /*"Loading languages"*/ STR(1231), fn });
		VarType map = json_load({ fn });
		if (!ds_map_valid(map))
			return IntType(0);
		global::load_format = DsMap(map).Value(/*"format"*/ STR(88));
		log({ /*"load_format"*/ STR(1232), global::load_format });
		VarType list, obj;
		list = DsMap(map).Value(/*"languages"*/ STR(1233));
		for (IntType i = IntType(0); i < ds_list_size((IntType)(list)); i++)
		{
			map = DsList(list).Value(i);
			VarType name, locale, fn;
			name = value_get_string(DsMap(map).Value(/*"name"*/ STR(802)), /*""*/ STR(0));
			locale = value_get_string(DsMap(map).Value(/*"locale"*/ STR(1234)), /*""*/ STR(0));
			fn = value_get_string(DsMap(map).Value(/*"filename"*/ STR(1235)), /*""*/ STR(0));
			language_remove(fn);
			IntType obj = (new obj_language)->id;
			ObjType(obj_language, obj)->name = name;
			ObjType(obj_language, obj)->locale = locale;
			ObjType(obj_language, obj)->filename = fn;
		}
		ds_list_destroy((IntType)(list));
		return 0.0;
	}
	
	void languages_save()
	{
		log({ /*"Saving languages"*/ STR(1236), languages_file });
		json_save_start(languages_file);
		json_save_object_start();
		json_save_var(/*"format"*/ STR(88), settings_format);
		json_save_array_start({ /*"languages"*/ STR(1233) });
		withAll (obj_language, noone)
		{
			json_save_object_start();
			json_save_var(/*"name"*/ STR(802), json_string_encode(self->name));
			json_save_var(/*"locale"*/ STR(1234), self->locale);
			json_save_var(/*"filename"*/ STR(1235), self->filename);
			json_save_object_done();
		}
		
		json_save_array_done();
		json_save_object_done();
		json_save_done();
		debug({ /*"Saved languges"*/ STR(1237) });
	}
	
}
