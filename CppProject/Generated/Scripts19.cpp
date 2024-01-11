/*
	NOTE:
	This file was autogenerated by CppGen, changes may be overwritten and forever lost!
	Modify at your own risk!
	
	[ Generated on 2023.12.26 22:36:37 ]
*/

#include "Scripts.hpp"

namespace CppProject
{
	RealType app_update_lists(ScopeAny self)
	{
		if (global::list_item_script == null_)
			return IntType(0);
		if (global::list_item_script_value == VarType())
			script_execute(self, { global::list_item_script });
		else
			script_execute(self, { global::list_item_script, global::list_item_script_value });
		
		global::list_item_script = null_;
		global::list_item_script_value = null_;
		global::list_item_value = null_;
		return 0.0;
	}
	
	void app_update_micro_animations()
	{
		RealType constantspeed;
		constantspeed = 0.1;
		if (global::_app->window_state == /*""*/ STR(0))
		{
			if (global::_app->timeline_zoom != global::_app->timeline_zoom_goal)
			{
				global::_app->timeline_zoom += (global::_app->timeline_zoom_goal - global::_app->timeline_zoom) / max({ IntType(1), 4.0 / global::delta });
				ObjType(obj_scrollbar, idInt(global::_app->timeline, hor_scroll))->value = max({ IntType(0), ObjType(obj_scrollbar, idInt(global::_app->timeline, hor_scroll))->value });
				ObjType(obj_scrollbar, idInt(global::_app->timeline, hor_scroll))->value_goal = max({ IntType(0), ObjType(obj_scrollbar, idInt(global::_app->timeline, hor_scroll))->value_goal });
			}
			if (abs(global::_app->timeline_zoom_goal - global::_app->timeline_zoom) < 0.0001)
				global::_app->timeline_zoom = global::_app->timeline_zoom_goal;
		}
		withAll (obj_scrollbar, global::_app->id)
		{
			if (!self->value_ease)
				self->value = self->value_goal;
			else
				self->value += (self->value_goal - self->value) / max({ IntType(1), 4.0 / global::delta });
			
			ObjType(value_animation, self->mousenear)->update(constantspeed);
		}
		
		withAll (obj_view, global::_app->id)
		{
			if (global::_app->setting_reduced_motion > 0)
				self->toolbar_alpha = self->toolbar_alpha_goal;
			else
				self->toolbar_alpha += (self->toolbar_alpha_goal - self->toolbar_alpha) / max({ IntType(1), 4.0 / global::delta });
			
			if (self->toolbar_alpha > .97 && self->toolbar_alpha_goal == IntType(1))
				self->toolbar_alpha = IntType(1);
		}
		
		for (IntType i = IntType(0); i < ds_list_size(global::microani_list); i++)
		{
			IntType ani = DsList(global::microani_list).Value(i);
			if (ObjType(micro_animation, ani)->steps_hidden > IntType(60) * IntType(3))
			{
				ds_list_add({ global::microani_delete_list, ani });
				continue;
			}
			ObjType(micro_animation, ani)->steps_alive++;
			ObjType(micro_animation, ani)->steps_hidden++;
			ObjType(micro_animation, ani)->update(constantspeed * 1.5);
		}
		for (IntType i = IntType(0); i < ds_list_size(global::microani_delete_list); i++)
		{
			VarType ani = DsList(global::microani_delete_list).Value(i);
			ds_list_delete_value(global::microani_list, ani);
			ds_map_delete(global::microanis, ObjType(micro_animation, ani)->key);
			delete Obj(ani);
		}
		ds_list_clear(global::microani_delete_list);
	}
	
	void app_update_minecraft_resources()
	{
		minecraft_update_patterns();
		minecraft_update_armor();
	}
	
	void app_update_mouse()
	{
		window_set_cursor(global::_app->mouse_cursor);
		global::_app->mouse_cursor = cr_default;
		global::_app->mouse_previous_x = global::_app->mouse_current_x;
		global::_app->mouse_previous_y = global::_app->mouse_current_y;
		global::_app->mouse_current_x = gmlGlobal::mouse_x;
		global::_app->mouse_current_y = gmlGlobal::mouse_y;
		global::_app->mouse_dx = gmlGlobal::mouse_x - global::_app->mouse_previous_x;
		global::_app->mouse_dy = gmlGlobal::mouse_y - global::_app->mouse_previous_y;
		global::_app->mouse_left_pressed = (!global::_app->mouse_left && mouse_check_button(mb_left));
		global::_app->mouse_left_released = (global::_app->mouse_left && !mouse_check_button(mb_left));
		global::_app->mouse_left = mouse_check_button(mb_left);
		global::_app->mouse_right_pressed = (!global::_app->mouse_right && mouse_check_button(mb_right));
		global::_app->mouse_right_released = (global::_app->mouse_right && !mouse_check_button(mb_right));
		global::_app->mouse_right = mouse_check_button(mb_right);
		global::_app->mouse_middle_pressed = (!global::_app->mouse_middle && mouse_check_button(mb_middle));
		global::_app->mouse_middle = mouse_check_button(mb_middle);
		global::_app->mouse_wheel = mouse_wheel_down() - mouse_wheel_up();
		if (global::_app->mouse_left_pressed)
		{
			global::_app->mouse_click_x = gmlGlobal::mouse_x;
			global::_app->mouse_click_y = gmlGlobal::mouse_y;
		}
		else
			if (global::_app->mouse_left)
				global::_app->mouse_move = max({ abs(gmlGlobal::mouse_x - global::_app->mouse_click_x), abs(gmlGlobal::mouse_y - global::_app->mouse_click_y) });
			else
				global::_app->mouse_move = IntType(0);
		
		
		if (global::_app->mouse_previous_x != gmlGlobal::mouse_x || global::_app->mouse_previous_y != gmlGlobal::mouse_y)
			global::_app->mouse_still = IntType(0);
		else
			global::_app->mouse_still++;
		
		if (global::_app->mouse_left_released || global::_app->mouse_right_released)
		{
			global::_app->mouse_wrap_x = IntType(0);
			global::_app->mouse_wrap_y = IntType(0);
		}
		global::_app->window_scroll_focus_prev = global::_app->window_scroll_focus;
		global::_app->window_scroll_focus = /*""*/ STR(0);
		if (global::_app->mouse_still == IntType(0))
		{
			global::_app->mouse_click_count = IntType(0);
			global::_app->mouse_click_timer = IntType(0);
		}
		if (global::_app->mouse_click_count == IntType(1))
		{
			global::_app->mouse_click_timer += (1.0 / gmlGlobal::fps) * IntType(1000);
			if (global::_app->mouse_click_timer < IntType(500) && global::_app->mouse_left_pressed)
				global::_app->mouse_click_count++;
			if (global::_app->mouse_click_timer >= IntType(500))
			{
				global::_app->mouse_click_count = IntType(0);
				global::_app->mouse_click_timer = IntType(0);
			}
		}
		if (global::_app->mouse_click_count >= IntType(2) && global::_app->mouse_left_pressed)
			global::_app->mouse_left_double_pressed = true;
		else
			global::_app->mouse_left_double_pressed = false;
		
		if (global::_app->mouse_click_count >= IntType(2) && global::_app->mouse_left_released)
		{
			global::_app->mouse_click_count = IntType(0);
			global::_app->mouse_click_timer = IntType(0);
		}
		if (global::_app->mouse_left_pressed && global::_app->mouse_click_count == IntType(0))
			global::_app->mouse_click_count++;
	}
	
	void app_update_play()
	{
		if (global::_app->timeline_playing > 0)
		{
			global::_app->timeline_marker = global::_app->timeline_playing_start_marker + ((current_time() - global::_app->timeline_playing_start_time) / 1000.0) * global::_app->project_tempo;
			if (global::_app->setting_timeline_frame_snap > 0)
				global::_app->timeline_marker = floor(global::_app->timeline_marker);
			if (global::_app->timeline_repeat > 0 || global::_app->timeline_seamless_repeat > 0)
			{
				if (global::_app->timeline_region_end != null_)
				{
					if (global::_app->timeline_marker >= global::_app->timeline_region_end)
						action_tl_play_beginning();
				}
				else
					if (global::_app->timeline_marker >= global::_app->timeline_length && global::_app->timeline_length > IntType(0))
						action_tl_play_beginning();
				
			}
		}
	}
	
	void app_update_previews()
	{
		ObjType(obj_preview, global::_app->lib_preview)->select = global::temp_edit;
		ObjType(obj_preview, global::_app->res_preview)->select = global::res_edit;
		ObjType(obj_preview, ObjType(obj_bench_settings, global::_app->bench_settings)->preview)->select = global::_app->bench_settings;
		withAll (obj_preview, global::_app->id)
		{
			if (self->last_select != self->select)
			{
				preview_reset_view(ScopeAny(self));
				particle_spawner_clear(ScopeAny(self));
				self->reset_view = true;
			}
			self->last_select = self->select;
			if (instance_exists(self->select) && Obj(self->select)->subAssetId != ID_obj_resource && idVar(self->select, type) == e_temp_type_PARTICLE_SPAWNER)
				particle_spawner_update(ScopeAny(self), self->id);
			self->spawn_laststep = global::current_step;
		}
		
	}
	
	void app_update_recent(ScopeAny self)
	{
		if (sBool(recent_add_wait) && sVar(window_busy) == /*""*/ STR(0))
			recent_add(self);
	}
	
	RealType app_update_tl_edit(ScopeAny self)
	{
		app_update_tl_edit_tabs(self);
		app_update_tl_edit_select(self);
		if (!instance_exists(global::temp_edit))
		{
			tab_close(self, sInt(template_editor));
			return IntType(0);
		}
		return 0.0;
	}
	
	void app_update_tl_edit_select(ScopeAny self)
	{
		withOne (obj_tab, sInt(frame_editor), self->id)
		{
			ObjType(obj_category, self->transform)->show = false;
			ObjType(obj_category, self->transform)->enabled = false;
			ObjType(obj_category, self->constraints)->enabled = false;
			ObjType(obj_category, self->constraints_path)->enabled = false;
			ObjType(obj_category, self->material)->enabled = false;
			ObjType(obj_category, self->particles)->enabled = false;
			ObjType(obj_category, self->light)->enabled = false;
			ObjType(obj_category, self->light)->has_spotlight = false;
			idReal(self->camera, show) = false;
			idBool(self->camera, enabled) = false;
			idVar(self->camera, video_template) = null_;
			ObjType(obj_category, self->sound)->enabled = false;
			idBool(self->text, enabled) = false;
			ObjType(obj_category, self->item)->enabled = false;
			ObjType(obj_category, self->keyframe)->enabled = false;
		}
		
		withOne (obj_tab, sInt(timeline_editor), self->id)
		{
			ObjType(obj_category, self->appearance)->enabled = false;
			ObjType(obj_category, self->audio)->enabled = false;
			ObjType(obj_category, self->path)->enabled = false;
		}
		
		sReal(select_kf_amount) = IntType(0);
		sInt(select_kf_single) = null_;
		sBool(timeline_settings) = false;
		sInt(timeline_settings_import_loop_tl) = null_;
		sStr(timeline_settings_walk_fn) = /*""*/ STR(0);
		sStr(timeline_settings_run_fn) = /*""*/ STR(0);
		sBool(timeline_settings_keyframes) = false;
		sBool(timeline_settings_keyframes_export) = false;
		if (!sBool(setting_tool_scale) && !(global::_app->setting_separate_tool_modes > 0))
			sVar(setting_tool_move) = true;
		BoolType checkwalk, checkexport;
		VarType checkexportobj;
		checkwalk = true;
		checkexport = true;
		checkexportobj = null_;
		withAll (obj_timeline, self->id)
		{
			if (!(self->selected > 0))
				continue;
			if (self->part_of == null_)
				global::_app->timeline_settings = true;
			if (self->keyframe_select != null_)
			{
				if (checkwalk)
				{
					checkwalk = false;
					global::_app->timeline_settings_import_loop_tl = null_;
					if (self->type == e_tl_type_CHARACTER)
					{
						if (self->keyframe_select_amount == IntType(1) && self->keyframe_select != null_ && ds_list_find_index(self->keyframe_list, self->keyframe_select) < ds_list_size(self->keyframe_list) - IntType(1))
						{
							checkwalk = true;
							global::_app->timeline_settings_import_loop_tl = self->id;
						}
					}
				}
				global::_app->timeline_settings_keyframes = true;
				if (checkexport)
				{
					VarType obj = ((self->part_of != null_) ? self->part_of : VarType(self->id));
					if (checkexportobj == null_)
					{
						checkexportobj = obj;
						global::_app->timeline_settings_keyframes_export = true;
					}
					else
						if (checkexportobj != obj)
						{
							checkexport = false;
							global::_app->timeline_settings_keyframes_export = false;
						}
					
				}
			}
			if (!(self->show_tool_position > 0) && !(global::_app->setting_separate_tool_modes > 0))
				global::_app->setting_tool_move = idVar(global::tl_edit, show_tool_position);
			if (self->value_type.Value(e_value_type_TRANSFORM))
				ObjType(obj_category, ObjType(obj_tab, global::_app->frame_editor)->transform)->enabled = true;
			if (self->value_type.Value(e_value_type_TRANSFORM_POS) && (self->type != e_tl_type_PATH && self->type != e_tl_type_PATH_POINT))
				ObjType(obj_category, ObjType(obj_tab, global::_app->frame_editor)->constraints)->enabled = true;
			if (self->value_type.Value(e_value_type_TRANSFORM_POS) && (self->type == e_tl_type_PATH_POINT))
				ObjType(obj_category, ObjType(obj_tab, global::_app->frame_editor)->constraints_path)->enabled = true;
			if (self->value_type.Value(e_value_type_MATERIAL))
				ObjType(obj_category, ObjType(obj_tab, global::_app->frame_editor)->material)->enabled = true;
			if (self->value_type.Value(e_value_type_PARTICLES))
				ObjType(obj_category, ObjType(obj_tab, global::_app->frame_editor)->particles)->enabled = true;
			if (self->value_type.Value(e_value_type_LIGHT))
				ObjType(obj_category, ObjType(obj_tab, global::_app->frame_editor)->light)->enabled = true;
			if (self->value_type.Value(e_value_type_SPOTLIGHT))
				ObjType(obj_category, ObjType(obj_tab, global::_app->frame_editor)->light)->has_spotlight = true;
			if (self->value_type.Value(e_value_type_CAMERA))
				idBool(ObjType(obj_tab, global::_app->frame_editor)->camera, enabled) = true;
			if (self->value_type.Value(e_value_type_SOUND))
				ObjType(obj_category, ObjType(obj_tab, global::_app->frame_editor)->sound)->enabled = true;
			if (self->value_type.Value(e_value_type_TEXT))
				idBool(ObjType(obj_tab, global::_app->frame_editor)->text, enabled) = true;
			if (self->value_type.Value(e_value_type_ITEM))
				ObjType(obj_category, ObjType(obj_tab, global::_app->frame_editor)->item)->enabled = true;
			if (self->value_type.Value(e_value_type_KEYFRAME))
				ObjType(obj_category, ObjType(obj_tab, global::_app->frame_editor)->keyframe)->enabled = true;
			if (self->value_type.Value(e_value_type_APPEARANCE))
				ObjType(obj_category, ObjType(obj_tab, global::_app->timeline_editor)->appearance)->enabled = true;
			if (self->value_type.Value(e_value_type_AUDIO))
				ObjType(obj_category, ObjType(obj_tab, global::_app->timeline_editor)->audio)->enabled = true;
			if (self->value_type.Value(e_value_type_PATH))
				ObjType(obj_category, ObjType(obj_tab, global::_app->timeline_editor)->path)->enabled = true;
			ObjType(obj_category, ObjType(obj_tab, global::_app->frame_editor)->transform)->show = true;
			if (self->value_type_show.Value(e_value_type_CAMERA))
				idReal(ObjType(obj_tab, global::_app->frame_editor)->camera, show) = true;
		}
		
		if (sInt(timeline_settings_import_loop_tl) != null_)
		{
			VarType name = idVar(idVar(ObjType(obj_timeline, sInt(timeline_settings_import_loop_tl))->temp, model_file), name);
			sStr(timeline_settings_walk_fn) = global::load_assets_startup_dir + mc_loops_directory + name + /*"_walk.miframes"*/ STR(707);
			sStr(timeline_settings_run_fn) = global::load_assets_startup_dir + mc_loops_directory + name + /*"_run.miframes"*/ STR(708);
			if (!file_exists(sStr(timeline_settings_walk_fn)))
			{
				name = idVar(ObjType(obj_timeline, sInt(timeline_settings_import_loop_tl))->temp, model_name);
				sStr(timeline_settings_walk_fn) = global::load_assets_startup_dir + mc_loops_directory + name + /*"_walk.miframes"*/ STR(707);
			}
			if (!file_exists(sStr(timeline_settings_run_fn)))
			{
				name = idVar(ObjType(obj_timeline, sInt(timeline_settings_import_loop_tl))->temp, model_name);
				sStr(timeline_settings_run_fn) = global::load_assets_startup_dir + mc_loops_directory + name + /*"_run.miframes"*/ STR(708);
			}
		}
	}
	
	void app_update_tl_edit_tabs(ScopeAny self)
	{
		BoolType showtl, showkf;
		showtl = false;
		showkf = false;
		if (global::tl_edit_amount > IntType(0))
		{
			showtl = true;
			if (idVar(global::tl_edit, type) == e_tl_type_AUDIO)
				showkf = (idVar(global::tl_edit, keyframe_select) != null_);
			else
				showkf = true;
			
		}
		if (showtl)
			tab_show(self, sInt(timeline_editor));
		else
			tab_close(self, sInt(timeline_editor));
		
		if (showkf)
			tab_show(self, sInt(frame_editor));
		else
			tab_close(self, sInt(frame_editor));
		
	}
	
	void app_update_toasts()
	{
		if (global::_app->toast_script != null_)
		{
			if (global::_app->toast_script_value != null_)
				script_execute(ScopeAny(global::_app->id), { global::_app->toast_script, global::_app->toast_script_value });
			else
				script_execute(ScopeAny(global::_app->id), { global::_app->toast_script });
			
		}
		global::_app->toast_script = null_;
		global::_app->toast_script_value = null_;
		withAll (obj_toast, global::_app->id)
		{
			if (self->remove)
			{
				if (global::_app->setting_reduced_motion > 0)
					self->remove_alpha = IntType(0);
				else
					self->remove_alpha -= (.1 * global::delta);
				
			}
		}
		
		withAll (obj_toast, global::_app->id)
		{
			if (self->remove && self->remove_alpha < IntType(0))
				withOne (app, global::_app->id, self->id)
					toast_close(ScopeAny(self), self.otherId);
			
		}
		
		global::_app->toast_amount = ds_list_size(global::_app->toast_list);
		RealType toasty = global::_app->window_height;
		for (RealType i = global::_app->toast_amount - IntType(1); i >= IntType(0); i--)
		{
			IntType toast = DsList(global::_app->toast_list).Value(i);
			if (ObjType(obj_toast, toast)->remove)
				continue;
			withOne (obj_toast, toast, global::_app->id)
			{
				toasty -= (16.0 + self->toast_height);
				self->toast_goal_y = toasty;
				self->toast_y += (self->toast_goal_y - self->toast_y) / max({ IntType(1), 2.5 / global::delta });
			}
			
		}
	}
	
	RealType app_update_window()
	{
		if (global::_app->window_width != window_get_width() || global::_app->window_height != window_get_height())
		{
			RealType ww, hh;
			IntType xx, yy;
			ww = window_get_width();
			hh = window_get_height();
			if (ww <= IntType(0) || hh <= IntType(0))
				return IntType(0);
			xx = window_get_x();
			yy = window_get_y();
			display_reset(IntType(0), (IntType)(false));
			window_set_rectangle(xx, yy, (IntType)(ww), (IntType)(hh));
			surface_resize(gmlGlobal::application_surface, (IntType)(ww), (IntType)(hh));
			camera_set_view_pos(global::cam_window, 0.0, 0.0);
			camera_set_view_size(global::cam_window, ww, hh);
			view_set_wport(IntType(0), (IntType)(ww));
			view_set_hport(IntType(0), (IntType)(hh));
			global::_app->window_width = ww;
			global::_app->window_height = hh;
		}
		return 0.0;
	}
	
	RealType app_update_work_camera(ScopeAny self)
	{
		if (sBool(cam_work_jump))
		{
			sBool(cam_work_jump) = false;
			return IntType(0);
		}
		if (sVar(window_busy) == /*""*/ STR(0))
		{
			if (global::tl_edit != null_)
			{
				sInt(cam_work_focus_tl) = global::tl_edit;
				if (idBool(sInt(cam_work_focus_tl), world_pos_2d_error))
					sInt(cam_work_focus_tl) = null_;
				if (sInt(cam_work_focus_tl) > 0)
					sVar(cam_work_focus) = point3D_copy(idVar(sInt(cam_work_focus_tl), world_pos));
			}
			else
				sInt(cam_work_focus_tl) = null_;
			
		}
		sVar(cam_work_zoom) += (sVar(cam_work_zoom_goal) - sVar(cam_work_zoom)) / max({ IntType(1), 3.0 / global::delta });
		sVar(cam_work_zoom) = clamp(sVar(cam_work_zoom), IntType(1), sVar(project_render_distance));
		if (sVec(cam_work_focus_last).Real(X_) != sVar(cam_work_focus).Value(X_) || sVec(cam_work_focus_last).Real(Y_) != sVar(cam_work_focus).Value(Y_) || sVec(cam_work_focus_last).Real(Z_) != sVar(cam_work_focus).Value(Z_))
			camera_work_set_angle();
		sVec(cam_work_focus_last) = point3D_copy(sVar(cam_work_focus));
		camera_work_set_from(self);
		return 0.0;
	}
	
	BoolType asset_load(ScopeAny self, VarArgs argument)
	{
		IntType argument_count = argument.Size();
		VarType fn;
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				history_destroy_loaded(self);
			
			tl_update_length();
			tl_update_list(self);
			ObjType(obj_preview, sInt(lib_preview))->update = true;
			ObjType(obj_preview, sInt(res_preview))->update = true;
			return false;
		}
		else
			if (sReal(history_redo) > 0)
				fn = ObjType(obj_history, global::history_data)->filename;
			else
			{
				if (argument_count > IntType(0))
					fn = argument[IntType(0)];
				else
					fn = file_dialog_open_asset();
				
			}
		
		
		ArrType path_array = string_split(fn, /*"\n"*/ STR(710));
		IntType path_array_count = array_length(VarType::CreateRef(path_array));
		show_debug_message(/*"FILE COUNT = "*/ STR(711) + string(path_array_count));
		if (path_array_count == IntType(0))
		{
			return false;
		}
		ds_list_clear(ObjType(obj_popup, sInt(popup_importimage))->filenames);
		for (IntType i = IntType(0); i < path_array_count; i += IntType(1))
		{
			fn = path_array.Value(i);
			if (fn == /*""*/ STR(0) || !file_exists_lib(fn))
				return false;
			StringType ext = string_lower(filename_ext(fn));
			switch (StringType(ext).id)
			{
				case 10: // .png
				case 712: // .jpg
				case 713: // .jpeg
				case 714: // .dat
				{
					log({ /*"Opening image"*/ STR(715), fn });
					ds_list_add({ ObjType(obj_popup, sInt(popup_importimage))->filenames, fn });
					show_debug_message(fn);
				}
			}
			
		}
		for (IntType i = IntType(0); i < path_array_count; i += IntType(1))
		{
			fn = path_array.Value(i);
			if (fn == /*""*/ STR(0) || !file_exists_lib(fn))
				return false;
			StringType ext = string_lower(filename_ext(fn));
			if (ext == /*".zip"*/ STR(7))
			{
				StringType validfile = unzip_asset(fn);
				if (file_exists_lib(validfile))
				{
					fn = validfile;
					ext = filename_ext(fn);
				}
				else
				{
					if (directory_exists_lib(unzip_directory + /*"assets"*/ STR(716)))
						action_res_pack_load(self, fn);
					else
						error(/*"erroropenassetzip"*/ STR(717));
					
					return false;
				}
				
			}
			BoolType legacy = false;
			switch (StringType(ext).id)
			{
				case 718: // .miobject
				case 719: // .miparticles
				case 720: // .miproject
				{
					legacy = false;
					break;
				}
				case 721: // .object
				case 722: // .particles
				case 723: // .mproj
				case 724: // .mani
				{
					legacy = true;
					break;
				}
				case 37: // .miframes
				case 725: // .keyframes
				{
					log({ /*"Opening keyframes"*/ STR(38), fn });
					action_tl_keyframes_load(self, fn);
					return true;
				}
				case 726: // .schematic
				case 727: // .nbt
				case 728: // .blocks
				{
					log({ /*"Opening scenery"*/ STR(729), fn });
					action_lib_scenery_load(self, fn);
					return true;
				}
				case 730: // .mimodel
				case 731: // .json
				{
					log({ /*"Opening model"*/ STR(732), fn });
					action_res_model_load(self, fn);
					return true;
				}
				case 733: // .mp3
				case 734: // .wav
				case 735: // .ogg
				case 736: // .flac
				case 737: // .wma
				case 738: // .m4a
				{
					log({ /*"Opening audio"*/ STR(739), fn });
					action_res_sound_load(self, fn);
					return true;
				}
				case 740: // .ttf
				{
					log({ /*"Adding font"*/ STR(741), fn });
					action_res_font_load(self, fn);
					return true;
				}
				case 10: // .png
				case 712: // .jpg
				case 713: // .jpeg
				case 714: // .dat
				{
					log({ /*"Opening image"*/ STR(715), fn });
					show_debug_message(fn);
					popup_show(self, sInt(popup_importimage));
					return true;
				}
			}
			
			IntType hobj = null_;
			if (!(sReal(history_redo) > 0))
				hobj = history_set(self, ID_asset_load);
			IntType rootmap;
			if (!legacy)
			{
				log({ /*"Opening asset"*/ STR(742), fn });
				rootmap = project_load_start(fn);
				if (rootmap == null_)
					return false;
			}
			else
			{
				log({ /*"Opening legacy asset"*/ STR(743), fn });
				if (!project_load_legacy_start(fn))
					return false;
			}
			
			project_reset_loaded(self);
			global::save_folder = sStr(project_folder);
			global::load_folder = filename_dir(fn);
			log({ /*"save_folder"*/ STR(744), global::save_folder });
			log({ /*"load_folder"*/ STR(745), global::load_folder });
			switch (StringType(ext).id)
			{
				case 720: // .miproject
				case 718: // .miobject
				{
					project_load_objects(rootmap);
					project_load_find_save_ids(self);
					project_load_update(self);
					break;
				}
				
				case 721: // .object
				{
					project_load_legacy_objects();
					project_load_find_save_ids(self);
					project_load_update(self);
					buffer_delete(global::buffer_current);
					break;
				}
				
				case 719: // .miparticles
				{
					IntType temp = (new obj_template)->id;
					withOne (obj_template, temp, self->id)
					{
						self->loaded = true;
						self->load_id = self->save_id;
						DsMap(global::save_id_map)[self->load_id] = self->load_id;
						self->type = e_temp_type_PARTICLE_SPAWNER;
						project_load_particles(ScopeAny(self), DsMap(rootmap).Value(/*"particles"*/ STR(551)));
						sortlist_add(idInt(self.otherId, lib_list), self->id);
					}
					
					project_load_objects(rootmap);
					project_load_find_save_ids(self);
					withOne (obj_template, temp, self->id)
						withOne (obj_timeline, temp_animate(ScopeAny(self)), self->id)
							self->loaded = true;
					
					
					project_load_update(self);
					break;
				}
				
				case 722: // .particles
				{
					IntType temp = (new obj_template)->id;
					withOne (obj_template, temp, self->id)
					{
						self->loaded = true;
						self->load_id = self->save_id;
						DsMap(global::save_id_map)[self->load_id] = self->load_id;
						self->type = e_temp_type_PARTICLE_SPAWNER;
						project_load_legacy_particles(ScopeAny(self));
						sortlist_add(idInt(self.otherId, lib_list), self->id);
					}
					
					project_load_legacy_objects();
					project_load_find_save_ids(self);
					withOne (obj_template, temp, self->id)
						withOne (obj_timeline, temp_animate(ScopeAny(self)), self->id)
							self->loaded = true;
					
					
					project_load_update(self);
					buffer_delete(global::buffer_current);
					break;
				}
				
				case 723: // .mproj
				{
					withOne (obj_data, (new obj_data)->id, self->id)
					{
						project_load_legacy_project(ScopeAny(self));
						instance_destroy(ScopeAny(self));
					}
					
					project_load_legacy_objects();
					project_load_find_save_ids(self);
					project_load_update(self);
					buffer_delete(global::buffer_current);
					break;
				}
				
				case 724: // .mani
				{
					project_load_legacy_beta(self, false);
					project_load_find_save_ids(self);
					project_load_update(self);
					buffer_delete(global::buffer_current);
					break;
				}
				
			}
			
			withOne (obj_history, hobj, self->id)
			{
				self->filename = fn;
				history_save_loaded(self);
			}
			
			project_reset_loaded(self);
			log({ /*"Asset loaded"*/ STR(746) });
		}
		return true;
	}
	
	void background_ground_startup()
	{
		RealType totalsize, size, rep;
		log({ /*"Ground vbuffer init"*/ STR(747) });
		totalsize = ((IntType)(global::_app->project_render_distance / IntType(256))) * IntType(256);
		size = totalsize / 16.0;
		rep = size / 16.0;
		global::_app->background_ground_texture = null_;
		global::_app->background_ground_texture_material = null_;
		global::_app->background_ground_texture_normal = null_;
		global::_app->background_ground_ani = false;
		global::_app->background_ground_material_ani = false;
		global::_app->background_ground_normal_ani = false;
		global::_app->background_ground_ani_texture[IntType(0)] = null_;
		global::_app->background_ground_ani_texture_material[IntType(0)] = null_;
		global::_app->background_ground_ani_tex_normal[IntType(0)] = null_;
		global::_app->background_ground_vbuffer = vbuffer_start();
		for (RealType xx = -totalsize; xx < totalsize; xx += size)
		{
			for (RealType yy = -totalsize; yy < totalsize; yy += size)
			{
				vertex_add({ xx, yy, -0.01, IntType(0), IntType(0), IntType(1), IntType(0), IntType(0) });
				vertex_add({ xx + size, yy, -0.01, IntType(0), IntType(0), IntType(1), rep, IntType(0) });
				vertex_add({ xx, yy + size, -0.01, IntType(0), IntType(0), IntType(1), IntType(0), rep });
				vertex_add({ xx + size, yy, -0.01, IntType(0), IntType(0), IntType(1), rep, IntType(0) });
				vertex_add({ xx + size, yy + size, -0.01, IntType(0), IntType(0), IntType(1), rep, rep });
				vertex_add({ xx, yy + size, -0.01, IntType(0), IntType(0), IntType(1), IntType(0), rep });
			}
		}
		vbuffer_done();
	}
	
	RealType background_ground_update_texture(ScopeAny self)
	{
		if (!idBool(sVar(background_ground_tex), ready) || (sVar(background_ground_slot) == sVar(background_ground_slot_prev) && idVar(sVar(background_ground_tex), save_id) == sVar(background_ground_tex_prev)))
			return IntType(0);
		sVar(background_ground_slot_prev) = sVar(background_ground_slot);
		sVar(background_ground_tex_prev) = idVar(sVar(background_ground_tex), save_id);
		if (sBool(background_ground_ani))
		{
			if (sArr(background_ground_ani_texture).Value(IntType(0)) != null_)
				for (IntType f = IntType(0); f < block_sheet_ani_frames; f++)
					texture_free(sArr(background_ground_ani_texture).Value(f));
		}
		else
			if (sInt(background_ground_texture) != null_)
				texture_free(sInt(background_ground_texture));
		
		RealType size, bx, by;
		IntType surf;
		VarType tex;
		if (sVar(background_ground_slot) < ds_list_size((IntType)(ObjType(obj_minecraft_assets, global::mc_assets)->block_texture_list)))
		{
			sBool(background_ground_ani) = false;
			sVar(background_ground_name) = DsList(ObjType(obj_minecraft_assets, global::mc_assets)->block_texture_list).Value(sVar(background_ground_slot));
			size = texture_width(idInt(sVar(background_ground_tex), block_sheet_texture)) / block_sheet_width;
			bx = (mod(sVar(background_ground_slot), block_sheet_width)) * size;
			by = ((IntType)(sVar(background_ground_slot) / block_sheet_width)) * size;
		}
		else
		{
			if (idVar(sVar(background_ground_tex), block_sheet_ani_texture) == null_)
			{
				sBool(background_ground_ani) = false;
				sInt(background_ground_texture) = texture_create_missing();
				sVar(background_ground_name) = /*""*/ STR(0);
				return IntType(0);
			}
			RealType slot = sVar(background_ground_slot) - ds_list_size((IntType)(ObjType(obj_minecraft_assets, global::mc_assets)->block_texture_list));
			sBool(background_ground_ani) = true;
			sVar(background_ground_name) = DsList(ObjType(obj_minecraft_assets, global::mc_assets)->block_texture_ani_list).Value(slot);
			size = texture_width(idVar(sVar(background_ground_tex), block_sheet_ani_texture).Value(IntType(0))) / block_sheet_ani_width;
			bx = (mod(slot, block_sheet_ani_width)) * size;
			by = ((IntType)(slot / block_sheet_ani_width)) * size;
		}
		
		draw_texture_start();
		surf = surface_create((IntType)(size), (IntType)(size));
		surface_set_target(surf);
	{
		if (sBool(background_ground_ani))
		{
			for (IntType f = IntType(0); f < block_sheet_ani_frames; f++)
			{
				draw_clear_alpha(c_black, 0.0);
				draw_texture_part({ idVar(sVar(background_ground_tex), block_sheet_ani_texture).Value(f), IntType(0), IntType(0), bx, by, size, size });
				sArr(background_ground_ani_texture)[f] = texture_surface(surf);
				sprite_set_texture_page(sArr(background_ground_ani_texture).Value(f), false);
			}
		}
		else
		{
			draw_clear_alpha(c_black, 0.0);
			draw_texture_part({ idInt(sVar(background_ground_tex), block_sheet_texture), IntType(0), IntType(0), bx, by, size, size });
			sInt(background_ground_texture) = texture_surface(surf);
			sprite_set_texture_page(sInt(background_ground_texture), false);
		}
		
	}
		surface_reset_target();
		surface_free(surf);
		draw_texture_done();
		return 0.0;
	}
	
	RealType background_ground_update_texture_material(ScopeAny self)
	{
		if (!idBool(sVar(background_ground_tex_material), ready) || (sVar(background_ground_slot) == sVar(background_ground_slot_material) && idVar(sVar(background_ground_tex_material), save_id) == sVar(background_ground_tex_material_prev)))
			return IntType(0);
		sVar(background_ground_slot_material) = sVar(background_ground_slot);
		sVar(background_ground_tex_material_prev) = idVar(sVar(background_ground_tex_material), save_id);
		if (sBool(background_ground_material_ani))
		{
			if (sArr(background_ground_ani_texture_material).Value(IntType(0)) != null_)
				for (IntType f = IntType(0); f < block_sheet_ani_frames; f++)
					texture_free(sArr(background_ground_ani_texture_material).Value(f));
		}
		else
			if (sInt(background_ground_texture_material) != null_)
				texture_free(sInt(background_ground_texture_material));
		
		RealType size, bx, by;
		IntType surf;
		VarType tex;
		if (sVar(background_ground_slot) < ds_list_size((IntType)(ObjType(obj_minecraft_assets, global::mc_assets)->block_texture_list)))
		{
			sBool(background_ground_material_ani) = false;
			size = ceil(texture_width(idInt(sVar(background_ground_tex_material), block_sheet_texture_material)) / block_sheet_width);
			bx = (mod(sVar(background_ground_slot), block_sheet_width)) * size;
			by = ((IntType)(sVar(background_ground_slot) / block_sheet_width)) * size;
		}
		else
		{
			if (idVar(sVar(background_ground_tex_material), block_sheet_ani_texture_material) == null_)
			{
				sBool(background_ground_material_ani) = false;
				sInt(background_ground_texture_material) = texture_create_fill(c_black);
				return IntType(0);
			}
			RealType slot = sVar(background_ground_slot) - ds_list_size((IntType)(ObjType(obj_minecraft_assets, global::mc_assets)->block_texture_list));
			sBool(background_ground_material_ani) = true;
			size = ceil(texture_width(idVar(sVar(background_ground_tex_material), block_sheet_ani_texture_material).Value(IntType(0))) / block_sheet_ani_width);
			bx = (mod(slot, block_sheet_ani_width)) * size;
			by = ((IntType)(slot / block_sheet_ani_width)) * size;
		}
		
		draw_texture_start();
		surf = surface_create((IntType)(size), (IntType)(size));
		surface_set_target(surf);
	{
		if (sBool(background_ground_material_ani))
		{
			for (IntType f = IntType(0); f < block_sheet_ani_frames; f++)
			{
				draw_clear_alpha(c_black, 0.0);
				draw_texture_part({ idVar(sVar(background_ground_tex_material), block_sheet_ani_texture_material).Value(f), IntType(0), IntType(0), bx, by, size, size });
				sArr(background_ground_ani_texture_material)[f] = texture_surface(surf);
			}
		}
		else
		{
			draw_clear_alpha(c_black, 0.0);
			draw_texture_part({ idInt(sVar(background_ground_tex_material), block_sheet_texture_material), IntType(0), IntType(0), bx, by, size, size });
			sInt(background_ground_texture_material) = texture_surface(surf);
		}
		
	}
		surface_reset_target();
		surface_free(surf);
		draw_texture_done();
		return 0.0;
	}
	
	RealType background_ground_update_texture_normal(ScopeAny self)
	{
		if (!idBool(sVar(background_ground_tex_normal), ready) || (sVar(background_ground_slot) == sVar(background_ground_slot_normal) && idVar(sVar(background_ground_tex_normal), save_id) == sVar(background_ground_tex_normal_prev)))
			return IntType(0);
		sVar(background_ground_slot_normal) = sVar(background_ground_slot);
		sVar(background_ground_tex_normal_prev) = idVar(sVar(background_ground_tex_normal), save_id);
		if (sBool(background_ground_normal_ani))
		{
			if (sArr(background_ground_ani_tex_normal).Value(IntType(0)) != null_)
				for (IntType f = IntType(0); f < block_sheet_ani_frames; f++)
					texture_free(sArr(background_ground_ani_texture_normal).Value(f));
		}
		else
			if (sInt(background_ground_texture_normal) != null_)
				texture_free(sInt(background_ground_texture_normal));
		
		RealType size, bx, by;
		IntType surf;
		VarType tex;
		if (sVar(background_ground_slot) < ds_list_size((IntType)(ObjType(obj_minecraft_assets, global::mc_assets)->block_texture_list)))
		{
			sBool(background_ground_normal_ani) = false;
			size = ceil(texture_width(idInt(sVar(background_ground_tex_normal), block_sheet_tex_normal)) / block_sheet_width);
			bx = (mod(sVar(background_ground_slot), block_sheet_width)) * size;
			by = ((IntType)(sVar(background_ground_slot) / block_sheet_width)) * size;
		}
		else
		{
			if (idVar(sVar(background_ground_tex_normal), block_sheet_ani_tex_normal) == null_)
			{
				sBool(background_ground_normal_ani) = false;
				sInt(background_ground_texture_normal) = sprite_duplicate(ID_spr_default_normal);
				return IntType(0);
			}
			RealType slot = sVar(background_ground_slot) - ds_list_size((IntType)(ObjType(obj_minecraft_assets, global::mc_assets)->block_texture_list));
			sBool(background_ground_normal_ani) = true;
			size = ceil(texture_width(idVar(sVar(background_ground_tex_normal), block_sheet_ani_tex_normal).Value(IntType(0))) / block_sheet_ani_width);
			bx = (mod(slot, block_sheet_ani_width)) * size;
			by = ((IntType)(slot / block_sheet_ani_width)) * size;
		}
		
		draw_texture_start();
		surf = surface_create((IntType)(size), (IntType)(size));
		surface_set_target(surf);
	{
		if (sBool(background_ground_normal_ani))
		{
			for (IntType f = IntType(0); f < block_sheet_ani_frames; f++)
			{
				draw_clear_alpha(c_black, 0.0);
				draw_texture_part({ idVar(sVar(background_ground_tex_normal), block_sheet_ani_tex_normal).Value(f), IntType(0), IntType(0), bx, by, size, size });
				sArr(background_ground_ani_texture_normal)[f] = texture_surface(surf);
			}
		}
		else
		{
			draw_clear_alpha(c_black, 0.0);
			draw_texture_part({ idInt(sVar(background_ground_tex_normal), block_sheet_tex_normal), IntType(0), IntType(0), bx, by, size, size });
			sInt(background_ground_texture_normal) = texture_surface(surf);
		}
		
	}
		surface_reset_target();
		surface_free(surf);
		draw_texture_done();
		return 0.0;
	}
	
}
