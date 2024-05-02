//tab_frame_editor_copy_scale()

function tab_frame_editor_copy_scale()
{
	if(tl_edit.type = e_tl_type.PATH_POINT)
	return 0
	
	tab_control_switch()
	draw_button_collapse("copyscale", collapse_map[?"copyscale"], null, true, "frameeditorcopyscale", "frameeditorcopyscaletip")
	tab_next()
	
	if (collapse_map[?"copyscale"])
	{
		tab_collapse_start()
		var text;
		
		// Target object
		if (tl_edit.value[e_value.SCALE_TARGET] != null)
			text = tl_edit.value[e_value.SCALE_TARGET].display_name
		else
			text = text_get("listnone")
		
		tab_control_menu()
		draw_button_menu("frameeditorcopyscaletarget",e_menu.TIMELINE, dx, dy, dw, 24, tl_edit.value[e_value.SCALE_TARGET], text, action_tl_frame_copy_scale_target)
		tab_next()
		
		dy += 12
		draw_label(text_get("frameeditorcopyscalecopyaxis"), dx, dy, fa_left, fa_middle, c_text_secondary, a_text_secondary, font_label)
		dy += 8
		
		tab_control_checkbox()
		draw_checkbox("frameeditorcopyscalex", dx, dy, tl_edit.value[e_value.COPY_SCALE_X], action_tl_frame_copy_scale_x)
		tab_next(false)
		
		tab_control_checkbox()
		draw_checkbox("frameeditorcopyscaley", dx, dy, (setting_z_is_up ? tl_edit.value[e_value.COPY_SCALE_Y] : tl_edit.value[e_value.COPY_SCALE_Z]), (setting_z_is_up ? action_tl_frame_copy_scale_y : action_tl_frame_copy_scale_z))
		tab_next(false)
		
		tab_control_checkbox()
		draw_checkbox("frameeditorcopyscalez", dx, dy, (setting_z_is_up ? tl_edit.value[e_value.COPY_SCALE_Z] : tl_edit.value[e_value.COPY_SCALE_Y]), (setting_z_is_up ? action_tl_frame_copy_scale_z : action_tl_frame_copy_scale_y))
		tab_next()
		
		tab_collapse_end()
	}
}