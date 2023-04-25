/*
	NOTE:
	This file was autogenerated by CppGen, changes may be overwritten and forever lost!
	Modify at your own risk!
	
	[ Generated on 2023.04.25 00:08:41 ]
*/

#include "Scripts.hpp"

namespace CppProject
{
	void action_tl_play_start()
	{
		audio_stop_all();
		withAll (obj_timeline, noone)
		{
			if (self->type == e_tl_type_AUDIO && !(self->hide > 0) && global::_app->window_state != /*"export_movie"*/ STR(49))
			{
				for (IntType k = IntType(0); k < ds_list_size(self->keyframe_list); k++)
				{
					withOne (obj_keyframe, DsList(self->keyframe_list).Value(k), self->id)
					{
						self->sound_play_index = null_;
						if (self->value.Value(e_value_SOUND_OBJ) == null_ || !idBool(self->value.Value(e_value_SOUND_OBJ), ready))
							continue;
						if (self->position + tl_keyframe_length(self->id) < global::_app->timeline_marker)
							continue;
						if (self->position > global::_app->timeline_marker)
							break;
						self->sound_play_index = audio_play_sound(idInt(self->value.Value(e_value_SOUND_OBJ), sound_index), IntType(0), (self->value.Value(e_value_SOUND_END) > IntType(0) ? true : false));
						audio_sound_pitch(self->sound_play_index, self->value.Value(e_value_SOUND_PITCH));
						audio_sound_set_track_position(self->sound_play_index, (mod((self->value.Value(e_value_SOUND_START) + (global::_app->timeline_marker - self->position) / global::_app->project_tempo), ((idReal(self->value.Value(e_value_SOUND_OBJ), sound_samples) / self->value.Value(e_value_SOUND_PITCH)) / sample_rate_)) * self->value.Value(e_value_SOUND_PITCH)));
						audio_sound_gain(self->sound_play_index, self->value.Value(e_value_SOUND_VOLUME), 0.0);
					}
					
				}
			}
			else
				if (self->type == e_temp_type_PARTICLE_SPAWNER)
				{
					for (IntType k = IntType(0); k < ds_list_size(self->keyframe_list); k++)
					{
						if (ObjType(obj_keyframe, DsList(self->keyframe_list).Value(k))->value.Value(e_value_SPAWN) > 0 && ObjType(obj_keyframe, DsList(self->keyframe_list).Value(k))->position == global::_app->timeline_marker)
						{
							self->fire = true;
							break;
						}
					}
				}
			
		}
		
	}
	
	void action_tl_play_stop(ScopeAny self)
	{
		if (sReal(timeline_playing) > 0)
		{
			sVar(timeline_marker) = sVar(timeline_playing_last_marker);
			ObjType(obj_scrollbar, idInt(sVar(timeline), hor_scroll))->value_goal = sVar(timeline_playing_start_hor_scroll);
			action_tl_play_break(self);
		}
		else
			sVar(timeline_marker) = IntType(0);
		
	}
	
	void action_tl_remove(ScopeAny self)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
			{
				for (IntType t = IntType(0); t < self->tl_save_amount; t++)
					history_restore_tl(self->tl_save_obj.Value(t));
				history_restore_tl_select(self);
			}
			
		}
		else
		{
			IntType contexttl = null_;
			if (!(sReal(history_redo) > 0))
			{
				withOne (obj_history, history_set(self, ID_action_tl_remove), self->id)
				{
					self->tl_save_amount = IntType(0);
					history_save_tl_select(ScopeAny(self));
					self->tl_context_save_id = (global::list_item_value == null_ ? VarType(null_) : idVar(global::list_item_value, save_id));
					if (global::list_item_value != null_ && !(idReal(global::list_item_value, selected) > 0))
					{
						withOne (Object, global::list_item_value, self->id)
							tl_select_single(self);
						
					}
					history_save_tl_tree(ScopeAny(self), global::_app->id);
					history_restore_tl_select(self);
				}
				
				contexttl = save_id_find(ObjType(obj_history, sArr(history).Value(IntType(0)))->tl_context_save_id);
			}
			else
				contexttl = save_id_find(ObjType(obj_history, global::history_data)->tl_context_save_id);
			
			if (contexttl == null_ || idReal(contexttl, selected) > 0)
			{
				withAll (obj_timeline, self->id)
					if (self->selected > 0 && self->part_of == null_ && !self->delete_ready)
						tl_remove_clean(ScopeAny(self));
				
				tl_deselect_all();
			}
			else
			{
				withOne (Object, contexttl, self->id)
					if (sVar(part_of) == null_ && !sBool(delete_ready))
						tl_remove_clean(self);
				
			}
			
			withAll (obj_timeline, self->id)
				if (self->delete_ready)
					instance_destroy(ScopeAny(self));
			
		}
		
		sVar(project_ik_part_array) = null_;
		tl_update_list(self);
		tl_update_length();
		tl_update_matrix(self);
		app_update_tl_edit(self);
	}
	
	void action_tl_right()
	{
		global::_app->timeline_marker_move += (RealType)global::_app->project_tempo / gmlGlobal::room_speed;
		if (global::_app->setting_timeline_frame_snap > 0 || keyboard_check(vk_control))
			global::_app->timeline_marker = round(global::_app->timeline_marker_move);
		else
			global::_app->timeline_marker = global::_app->timeline_marker_move;
		
		if (global::_app->timeline_repeat > 0 || global::_app->timeline_seamless_repeat > 0)
		{
			if (global::_app->timeline_region_end != null_)
			{
				if (global::_app->timeline_marker >= global::_app->timeline_region_end)
					global::_app->timeline_marker = global::_app->timeline_region_start;
			}
			else
				if (global::_app->timeline_marker >= global::_app->timeline_length && global::_app->timeline_length > IntType(0))
					global::_app->timeline_marker = IntType(0);
			
		}
	}
	
	void action_tl_rotpoint(ScopeAny self, VarType val, VarType add)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
			{
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
				{
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
					{
						sVar(rot_point)[global::axis_edit] = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
						tl_update_rot_point(self);
					}
					
				}
			}
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
				{
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
					{
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						{
							sVar(rot_point)[global::axis_edit] = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
							tl_update_rot_point(self);
						}
						
					}
				}
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_rotpoint, true);
				withAll (obj_timeline, self->id)
				{
					if (!(self->selected > 0))
						continue;
					withOne (obj_history, hobj, self->id)
						history_save_var(self, self.otherId, ObjType(obj_timeline, self.otherId)->rot_point.Value(global::axis_edit), ObjType(obj_timeline, self.otherId)->rot_point.Value(global::axis_edit) * add + val);
					
					self->rot_point[global::axis_edit] = self->rot_point.Value(global::axis_edit) * add + val;
					tl_update_rot_point(ScopeAny(self));
				}
				
			}
		
		
		tl_update_matrix(self);
	}
	
	void action_tl_rotpoint_all(ScopeAny self, VarType point)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
			{
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
				{
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
					{
						sVar(rot_point) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
						tl_update_rot_point(self);
					}
					
				}
			}
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
				{
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
					{
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						{
							sVar(rot_point) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
							tl_update_rot_point(self);
						}
						
					}
				}
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_rotpoint_all, false);
				withAll (obj_timeline, self->id)
				{
					if (!(self->selected > 0))
						continue;
					withOne (obj_history, hobj, self->id)
						history_save_var(self, self.otherId, ObjType(obj_timeline, self.otherId)->rot_point, point);
					
					self->rot_point = point;
					tl_update_rot_point(ScopeAny(self));
				}
				
			}
		
		
		tl_update_matrix(self);
	}
	
	void action_tl_rotpoint_custom(ScopeAny self, VarType enable)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
			{
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
				{
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
					{
						sVar(rot_point_custom) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
						tl_update_rot_point(self);
					}
					
				}
			}
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
				{
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
					{
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						{
							sVar(rot_point_custom) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
							tl_update_rot_point(self);
						}
						
					}
				}
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_rotpoint_custom, false);
				withAll (obj_timeline, self->id)
				{
					if (!(self->selected > 0))
						continue;
					withOne (obj_history, hobj, self->id)
						history_save_var(self, self.otherId, ObjType(obj_timeline, self.otherId)->rot_point_custom, enable);
					
					self->rot_point_custom = enable;
					tl_update_rot_point(ScopeAny(self));
				}
				
			}
		
		
		tl_update_matrix(self);
	}
	
	void action_tl_scale_resize(ScopeAny self, VarType enable)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
			{
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
				{
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
					{
						sVar(scale_resize) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
						sBool(update_matrix) = true;
					}
					
				}
			}
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
				{
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
					{
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						{
							sVar(scale_resize) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
							sBool(update_matrix) = true;
						}
						
					}
				}
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_scale_resize, false);
				withAll (obj_timeline, self->id)
				{
					if (!(self->selected > 0))
						continue;
					withOne (obj_history, hobj, self->id)
						history_save_var(self, self.otherId, ObjType(obj_timeline, self.otherId)->scale_resize, enable);
					
					self->scale_resize = enable;
					self->update_matrix = true;
				}
				
			}
		
		
		tl_update_matrix(self);
	}
	
	void action_tl_search(ScopeAny self, VarType search)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_tl_search, sStr(timeline_search), search, true);
		sStr(timeline_search) = search.Str();
		tl_update_list(self);
	}
	
	void action_tl_select(ScopeAny self, VarType tl)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
			{
				history_restore_tl_select(self);
				for (IntType t = IntType(0); t < self->extend_amount; t++)
					withOne (Object, save_id_find(self->extend_save_id.Value(t)), self->id)
						sVar(tree_extend) = ObjType(obj_history, self.otherId)->extend_value.Value(t);
				
			}
			
		}
		else
		{
			BoolType shift;
			VarType par;
			IntType hobj;
			hobj = noone;
			if (sReal(history_redo) > 0)
			{
				tl = save_id_find(ObjType(obj_history, global::history_data)->tl_save_id);
				shift = ObjType(obj_history, global::history_data)->shift;
			}
			else
			{
				shift = keyboard_check(vk_shift);
				hobj = history_set(self, ID_action_tl_select);
				withOne (obj_history, hobj, self->id)
				{
					ObjType(obj_history, self->id)->tl_save_id = save_id_get(tl);
					ObjType(obj_history, self->id)->shift = shift;
					history_save_tl_select(ScopeAny(self));
					self->extend_amount = IntType(0);
				}
				
			}
			
			par = idVar(tl, parent);
			while (par != global::_app->id)
			{
				withOne (obj_history, hobj, self->id)
				{
					self->extend_save_id[self->extend_amount] = idVar(par, save_id);
					self->extend_value[self->extend_amount] = idVar(par, tree_extend);
					self->extend_amount++;
				}
				
				idVar(par, tree_extend) = true;
				par = idVar(par, parent);
			}
			
			if (!shift)
			{
				tl_deselect_all();
			}
			withOne (Object, tl, self->id)
			{
				tl_update_recursive_select(self);
				tl_select(self);
			}
			
		}
		
		app_update_tl_edit(self);
		tl_update_list(self);
	}
	
	void action_tl_select_all(ScopeAny self)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				history_restore_tl_select(self);
			
		}
		else
		{
			if (!(sReal(history_redo) > 0))
				withOne (obj_history, history_set(self, ID_action_tl_select_all), self->id)
					history_save_tl_select(ScopeAny(self));
			
			for (IntType t = IntType(0); t < ds_list_size(sInt(tree_list)); t++)
			{
				withOne (obj_timeline, DsList(sInt(tree_list)).Value(t), self->id)
				{
					tl_update_recursive_select(ScopeAny(self));
					tl_select(ScopeAny(self));
				}
				
			}
		}
		
		app_update_tl_edit(self);
	}
	
	void action_tl_select_area(ScopeAny self, RealType stl, RealType etl)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				history_restore_tl_select(self);
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					history_restore_tl_select_new(self);
				
			}
			else
			{
				IntType hobj;
				BoolType ctrl;
				hobj = history_set(self, ID_action_tl_select_area);
				ctrl = keyboard_check(vk_control);
				withOne (obj_history, hobj, self->id)
					history_save_tl_select(ScopeAny(self));
				
				for (RealType t = stl; t <= etl; t++)
				{
					withOne (Object, DsList(sInt(tree_visible_list)).Value(t), self->id)
					{
						if (!ctrl)
						{
							tl_update_recursive_select(self);
							tl_select(self);
						}
						else
							tl_deselect(self);
						
					}
					
				}
				withOne (obj_history, hobj, self->id)
					history_save_tl_select_new(ScopeAny(self));
				
			}
		
		
		app_update_tl_edit(self);
	}
	
	void action_tl_select_keyframes(ScopeAny self, VarType tl)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				history_restore_tl_select(self);
			
		}
		else
		{
			BoolType shift;
			if (sReal(history_redo) > 0)
			{
				shift = ObjType(obj_history, global::history_data)->shift;
				if (!shift)
					tl_deselect_all();
				for (IntType t = IntType(0); t < ObjType(obj_history, global::history_data)->tl_amount; t++)
				{
					tl = save_id_find(ObjType(obj_history, global::history_data)->tl_save_id.Value(t));
					withOne (Object, tl, self->id)
						tl_select(self);
					
					for (IntType k = IntType(0); k < ds_list_size(idInt(tl, keyframe_list)); k++)
						tl_keyframe_select(DsList(idInt(tl, keyframe_list)).Value(k));
				}
			}
			else
			{
				IntType hobj = history_set(self, ID_action_tl_select_keyframes);
				shift = keyboard_check(vk_shift);
				withOne (obj_history, hobj, self->id)
				{
					self->tl_amount = IntType(0);
					ObjType(obj_history, self->id)->shift = shift;
					history_save_tl_select(ScopeAny(self));
				}
				
				if (idReal(tl, selected) > 0)
				{
					withAll (obj_timeline, self->id)
					{
						if (!(self->selected > 0))
						{
							if (!shift)
								tl_deselect(ScopeAny(self));
							continue;
						}
						withOne (obj_history, hobj, self->id)
						{
							self->tl_save_id[self->tl_amount] = save_id_get(self.otherId);
							self->tl_amount++;
						}
						
						for (IntType k = IntType(0); k < ds_list_size(self->keyframe_list); k++)
							tl_keyframe_select(DsList(self->keyframe_list).Value(k));
					}
					
				}
				else
				{
					if (!shift)
						tl_deselect_all();
					ObjType(obj_history, hobj)->tl_save_id[IntType(0)] = save_id_get(tl);
					ObjType(obj_history, hobj)->tl_amount++;
					for (IntType k = IntType(0); k < ds_list_size(idInt(tl, keyframe_list)); k++)
						tl_keyframe_select(DsList(idInt(tl, keyframe_list)).Value(k));
				}
				
			}
			
		}
		
		app_update_tl_edit(self);
	}
	
	void action_tl_select_keyframes_after_marker(ScopeAny self)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				history_restore_tl_select(self);
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					history_restore_tl_select_new(self);
				
			}
			else
			{
				BoolType shift = keyboard_check(vk_shift);
				IntType hobj;
				hobj = history_set(self, ID_action_tl_select_keyframes_after_marker);
				withOne (obj_history, hobj, self->id)
					history_save_tl_select(ScopeAny(self));
				
				if (!shift)
					tl_deselect_all();
				withAll (obj_keyframe, self->id)
				{
					if (idVar(self->timeline, lock) > 0)
						continue;
					if (self->position >= global::_app->timeline_marker)
						tl_keyframe_select(self->id);
				}
				
				withOne (obj_history, hobj, self->id)
					history_save_tl_select_new(ScopeAny(self));
				
			}
		
		
		app_update_tl_edit(self);
	}
	
	void action_tl_select_keyframes_before_marker(ScopeAny self)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				history_restore_tl_select(self);
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					history_restore_tl_select_new(self);
				
			}
			else
			{
				BoolType shift = keyboard_check(vk_shift);
				IntType hobj;
				hobj = history_set(self, ID_action_tl_select_keyframes_before_marker);
				withOne (obj_history, hobj, self->id)
					history_save_tl_select(ScopeAny(self));
				
				if (!shift)
					tl_deselect_all();
				withAll (obj_keyframe, self->id)
				{
					if (idVar(self->timeline, lock) > 0)
						continue;
					if (self->position < global::_app->timeline_marker)
						tl_keyframe_select(self->id);
				}
				
				withOne (obj_history, hobj, self->id)
					history_save_tl_select_new(ScopeAny(self));
				
			}
		
		
		app_update_tl_edit(self);
	}
	
	void action_tl_select_keyframes_first(ScopeAny self)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				history_restore_tl_select(self);
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					history_restore_tl_select_new(self);
				
			}
			else
			{
				BoolType shift = keyboard_check(vk_shift);
				IntType hobj;
				hobj = history_set(self, ID_action_tl_select_keyframes_first);
				withOne (obj_history, hobj, self->id)
					history_save_tl_select(ScopeAny(self));
				
				if (!shift)
					tl_deselect_all();
				withAll (obj_timeline, self->id)
				{
					if (self->lock > 0 || ds_list_size(self->keyframe_list) == IntType(0))
						continue;
					tl_keyframe_select(DsList(self->keyframe_list).Value(IntType(0)));
				}
				
				withOne (obj_history, hobj, self->id)
					history_save_tl_select_new(ScopeAny(self));
				
			}
		
		
		app_update_tl_edit(self);
	}
	
	void action_tl_select_keyframes_last(ScopeAny self)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				history_restore_tl_select(self);
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					history_restore_tl_select_new(self);
				
			}
			else
			{
				BoolType shift = keyboard_check(vk_shift);
				IntType hobj;
				hobj = history_set(self, ID_action_tl_select_keyframes_last);
				withOne (obj_history, hobj, self->id)
					history_save_tl_select(ScopeAny(self));
				
				if (!shift)
					tl_deselect_all();
				withAll (obj_timeline, self->id)
				{
					if (self->lock > 0 || ds_list_size(self->keyframe_list) == IntType(0))
						continue;
					tl_keyframe_select(DsList(self->keyframe_list).Value(ds_list_size(self->keyframe_list) - IntType(1)));
				}
				
				withOne (obj_history, hobj, self->id)
					history_save_tl_select_new(ScopeAny(self));
				
			}
		
		
		app_update_tl_edit(self);
	}
	
	void action_tl_select_keyframes_region(ScopeAny self)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				history_restore_tl_select(self);
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					history_restore_tl_select_new(self);
				
			}
			else
			{
				BoolType shift = keyboard_check(vk_shift);
				IntType hobj;
				hobj = history_set(self, ID_action_tl_select_keyframes_region);
				withOne (obj_history, hobj, self->id)
					history_save_tl_select(ScopeAny(self));
				
				if (!shift)
					tl_deselect_all();
				withAll (obj_keyframe, self->id)
				{
					if (idVar(self->timeline, lock) > 0)
						continue;
					if (self->position >= global::_app->timeline_region_start && self->position <= global::_app->timeline_region_end)
						tl_keyframe_select(self->id);
				}
				
				withOne (obj_history, hobj, self->id)
					history_save_tl_select_new(ScopeAny(self));
				
			}
		
		
		app_update_tl_edit(self);
	}
	
	RealType action_tl_select_single(ScopeAny self, VarArgs argument)
	{
		IntType argument_count = argument.Size();
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				history_restore_tl_select(self);
			
			app_update_tl_edit(self);
		}
		else
		{
			VarType tl = null_;
			if (sReal(history_redo) > 0)
				tl = save_id_find(ObjType(obj_history, global::history_data)->tl_save_id);
			else
			{
				if (argument_count > IntType(1) && argument[IntType(1)] != null_)
				{
					withAll (obj_timeline, self->id)
					{
						if (self->type == argument[IntType(1)])
						{
							tl = self->id;
							break;
						}
					}
					
				}
				else
					tl = argument[IntType(0)];
				
				if (!(tl > 0))
					return IntType(0);
				if (global::tl_edit_amount == IntType(1) && global::tl_edit == tl)
					return IntType(1);
				withOne (obj_history, history_set(self, ID_action_tl_select_single), self->id)
				{
					self->tl_save_id = save_id_get(tl);
					history_save_tl_select(ScopeAny(self));
				}
				
			}
			
			withOne (Object, tl, self->id)
				tl_select_single(self);
			
			app_update_tl_edit_select(self);
			return IntType(1);
		}
		
		return 0.0;
	}
	
	void action_tl_shadows(ScopeAny self, VarType enable)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						sVar(shadows) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
			
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
							sVar(shadows) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
				
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_shadows, false);
				withAll (obj_timeline, self->id)
					if (self->selected > 0)
						action_tl_shadows_tree(self->id, enable, hobj);
				
			}
		
		
	}
	
	void action_tl_shadows_tree(VarType tl, VarType nval, VarType hobj)
	{
		withOne (obj_history, hobj, noone)
			history_save_var(self, tl, ObjType(obj_timeline, tl)->shadows, nval);
		
		ObjType(obj_timeline, tl)->shadows = nval;
		for (IntType i = IntType(0); i < ds_list_size(ObjType(obj_timeline, tl)->tree_list); i++)
			if (!(ObjType(obj_timeline, DsList(ObjType(obj_timeline, tl)->tree_list).Value(i))->selected > 0))
				action_tl_shadows_tree(DsList(ObjType(obj_timeline, tl)->tree_list).Value(i), nval, hobj);
	}
	
	void action_tl_ssao(ScopeAny self, VarType enable)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						sVar(ssao) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
			
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
							sVar(ssao) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
				
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_ssao, false);
				withAll (obj_timeline, self->id)
					if (self->selected > 0)
						action_tl_ssao_tree(self->id, enable, hobj);
				
			}
		
		
	}
	
	void action_tl_ssao_tree(VarType tl, VarType nval, VarType hobj)
	{
		withOne (obj_history, hobj, noone)
			history_save_var(self, tl, ObjType(obj_timeline, tl)->ssao, nval);
		
		ObjType(obj_timeline, tl)->ssao = nval;
		for (IntType i = IntType(0); i < ds_list_size(ObjType(obj_timeline, tl)->tree_list); i++)
			if (!(ObjType(obj_timeline, DsList(ObjType(obj_timeline, tl)->tree_list).Value(i))->selected > 0))
				action_tl_ssao_tree(DsList(ObjType(obj_timeline, tl)->tree_list).Value(i), nval, hobj);
	}
	
	void action_tl_text(ScopeAny self, VarType text)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						idVar(self->id, text) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
			
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
							idVar(self->id, text) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
				
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_text, true);
				withAll (obj_timeline, self->id)
				{
					if (!(self->selected > 0))
						continue;
					withOne (obj_history, hobj, self->id)
						history_save_var(self, self.otherId, ObjType(obj_timeline, self.otherId)->text, text);
					
					ObjType(obj_timeline, self->id)->text = text;
				}
				
			}
		
		
	}
	
	void action_tl_texture_blur(ScopeAny self, VarType enable)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						sVar(texture_blur) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
			
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
							sVar(texture_blur) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
				
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_texture_blur, false);
				withAll (obj_timeline, self->id)
					if (self->selected > 0)
						action_tl_texture_blur_tree(self->id, enable, hobj);
				
			}
		
		
	}
	
}
