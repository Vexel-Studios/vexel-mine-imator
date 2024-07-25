/// tab_frame_editor_copy_pos()

function tab_frame_editor_copy_pos()
{
	tab_control_switch()
	draw_button_collapse("copypos", collapse_map[?"copypos"], null, true, "frameeditorcopypos", "frameeditorcopypostip")
	tab_next()
	
	var taby = dy
	if (collapse_map[?"copypos"])
	{
		tab_collapse_start()

		// Target object
		var text;
		if (tl_edit.value[e_value.POS_TARGET] != null)
			text = tl_edit.value[e_value.POS_TARGET].display_name
		else
			text = text_get("listnone")
		
		tab_control_menu()
		draw_button_menu("frameeditorcopypostarget", e_menu.TIMELINE, dx, dy, dw, 24, tl_edit.value[e_value.POS_TARGET], text, action_tl_frame_copy_pos_target)
		tab_next()
		
		dy += 12
		togglebutton_add("frameeditorcopyposx", null, !tl_edit.value[e_value.COPY_POS_X], tl_edit.value[e_value.COPY_POS_X], action_tl_frame_copy_pos_x)
		togglebutton_add("frameeditorcopyposy", null, !(setting_z_is_up ? tl_edit.value[e_value.COPY_POS_Y] : tl_edit.value[e_value.COPY_POS_Z]), (setting_z_is_up ? tl_edit.value[e_value.COPY_POS_Y] : tl_edit.value[e_value.COPY_POS_Z]), (setting_z_is_up ? action_tl_frame_copy_pos_y : action_tl_frame_copy_pos_z))
		togglebutton_add("frameeditorcopyposz", null, !(setting_z_is_up ? tl_edit.value[e_value.COPY_POS_Z] : tl_edit.value[e_value.COPY_POS_Y]), (setting_z_is_up ? tl_edit.value[e_value.COPY_POS_Z] : tl_edit.value[e_value.COPY_POS_Y]), (setting_z_is_up ? action_tl_frame_copy_pos_z : action_tl_frame_copy_pos_y))
		
		tab_control_togglebutton()
		draw_togglebutton("frameeditorcopyposcopyaxis", dx, dy)
		tab_next()
		
		tab_control_checkbox()
		draw_checkbox("frameeditorcopyposchild", dx, dy, tl_edit.value[e_value.COPY_POS_CHILD], action_tl_frame_copy_pos_child)
		draw_checkbox("frameeditorcopyposbend", dx + dw/2, dy, tl_edit.value[e_value.COPY_POS_BEND], action_tl_frame_copy_pos_bend)
		tab_next()
		
		var mul = max(1, point3D_distance(tl_edit.world_pos, cam_from)) / 100
		
		microani_set("tabcopyposition", null, false, false, false)
		
		context_menu_group_temp = e_context_group.COPYPOS
		
		tab_frame_editor_buttons()
		draw_label(text_get("frameeditorcopyposoffset"), dx, dy + 12, fa_left, fa_middle, c_text_secondary, a_text_secondary, font_label)
		dy += 26
		
		var snapval = (dragger_snap ? setting_snap_size_position : snap_min)
		axis_edit = X
		textfield_group_add("frameeditorcopyposxoffset", tl_edit.value[e_value.COPY_POS_OFFSET_X], 0, action_tl_frame_copy_pos_offset_x, axis_edit, tab.constraints.tbx_copy_pos_offset_x, null, mul, -no_limit, no_limit)
		axis_edit = (setting_z_is_up ? Y : Z)
		textfield_group_add("frameeditorcopyposyoffset", (setting_z_is_up ? tl_edit.value[e_value.COPY_POS_OFFSET_Y] : tl_edit.value[e_value.COPY_POS_OFFSET_Z]), 0, (setting_z_is_up ? action_tl_frame_copy_pos_offset_y : action_tl_frame_copy_pos_offset_z), axis_edit, tab.constraints.tbx_copy_pos_offset_y, null, mul, -no_limit, no_limit)
		axis_edit = (setting_z_is_up ? Z : Y)
		textfield_group_add("frameeditorcopyposzoffset", (setting_z_is_up ? tl_edit.value[e_value.COPY_POS_OFFSET_Z] : tl_edit.value[e_value.COPY_POS_OFFSET_Y]), 0, (setting_z_is_up ? action_tl_frame_copy_pos_offset_z : action_tl_frame_copy_pos_offset_y), axis_edit, tab.constraints.tbx_copy_pos_offset_z, null, mul, -no_limit, no_limit)
		
		tab_control_textfield_group(false)
		draw_textfield_group("frameeditorcopyposoffset", dx, dy, dw, null, null, null, snapval, false, false, 1) 
		tab_next()
		
		// Blend
		tab_control_meter()
		draw_meter("frameeditorcopyposblend", dx, dy, dw, round(tl_edit.value[e_value.COPY_POS_BLEND] * 100), 0, 100, 100, 1, tab.constraints.tbx_copy_pos_blend, action_tl_frame_copy_pos_blend)
		tab_next()
		
		microani_set("tabcopyposition", null, false, false, false)
		microani_update(app_mouse_box(dx, taby, dw, dy - taby) && content_mouseon, false, false)
		
		tab_collapse_end()
	}
}