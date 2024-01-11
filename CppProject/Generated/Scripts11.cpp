/*
	NOTE:
	This file was autogenerated by CppGen, changes may be overwritten and forever lost!
	Modify at your own risk!
	
	[ Generated on 2023.12.26 22:36:37 ]
*/

#include "Scripts.hpp"

namespace CppProject
{
	void action_tl_frame_subsurface_color(ScopeAny self, VarType color)
	{
		tl_value_set_start(self, ID_action_tl_frame_subsurface_color, true);
		tl_value_set(self, { e_value_SUBSURFACE_COLOR, color, false });
		tl_value_set_done();
	}
	
	void action_tl_frame_subsurface_green(ScopeAny self, RealType val, VarType add)
	{
		tl_value_set_start(self, ID_action_tl_frame_subsurface_green, true);
		tl_value_set(self, { e_value_SUBSURFACE_RADIUS_GREEN, val / 100.0, add });
		tl_value_set_done();
	}
	
	void action_tl_frame_subsurface_red(ScopeAny self, RealType val, VarType add)
	{
		tl_value_set_start(self, ID_action_tl_frame_subsurface_red, true);
		tl_value_set(self, { e_value_SUBSURFACE_RADIUS_RED, val / 100.0, add });
		tl_value_set_done();
	}
	
	void action_tl_frame_text(ScopeAny self, VarType text)
	{
		tl_value_set_start(self, ID_action_tl_frame_text, true);
		tl_value_set(self, { e_value_TEXT, text, false });
		tl_value_set_done();
	}
	
	void action_tl_frame_texture_light_gobo(ScopeAny self, VarType object)
	{
		tl_value_set_start(self, ID_action_tl_frame_texture_light_gobo, false);
		tl_value_set(self, { e_value_TEXTURE_OBJ, object, false });
		tl_value_set_done();
	}
	
	void action_tl_frame_texture_material_obj(ScopeAny self, VarType object)
	{
		tl_value_set_start(self, ID_action_tl_frame_texture_material_obj, false);
		tl_value_set(self, { e_value_TEXTURE_MATERIAL_OBJ, object, false });
		tl_value_set_done();
	}
	
	void action_tl_frame_texture_normal_obj(ScopeAny self, VarType object)
	{
		tl_value_set_start(self, ID_action_tl_frame_texture_normal_obj, false);
		tl_value_set(self, { e_value_TEXTURE_NORMAL_OBJ, object, false });
		tl_value_set_done();
	}
	
	void action_tl_frame_texture_obj(ScopeAny self, VarType object)
	{
		tl_value_set_start(self, ID_action_tl_frame_texture_obj, false);
		tl_value_set(self, { e_value_TEXTURE_OBJ, object, false });
		tl_value_set_done();
	}
	
	void action_tl_frame_text_aa(ScopeAny self, VarType enable)
	{
		tl_value_set_start(self, ID_action_tl_frame_text_aa, false);
		tl_value_set(self, { e_value_TEXT_AA, enable, false });
		tl_value_set_done();
	}
	
	void action_tl_frame_text_font(ScopeAny self, VarType object)
	{
		tl_value_set_start(self, ID_action_tl_frame_text_font, false);
		tl_value_set(self, { e_value_TEXT_FONT, object, false });
		tl_value_set_done();
	}
	
	void action_tl_frame_text_halign(ScopeAny self, VarType halign)
	{
		tl_value_set_start(self, ID_action_tl_frame_text_halign, true);
		tl_value_set(self, { e_value_TEXT_HALIGN, halign, false });
		tl_value_set_done();
	}
	
	void action_tl_frame_text_outline(ScopeAny self, VarType enable)
	{
		tl_value_set_start(self, ID_action_tl_frame_text_outline, false);
		tl_value_set(self, { e_value_TEXT_OUTLINE, enable, false });
		tl_value_set_done();
	}
	
	void action_tl_frame_text_outline_color(ScopeAny self, VarType color)
	{
		tl_value_set_start(self, ID_action_tl_frame_text_outline_color, true);
		tl_value_set(self, { e_value_TEXT_OUTLINE_COLOR, color, false });
		tl_value_set_done();
	}
	
	void action_tl_frame_text_valign(ScopeAny self, VarType valign)
	{
		tl_value_set_start(self, ID_action_tl_frame_text_valign, true);
		tl_value_set(self, { e_value_TEXT_VALIGN, valign, false });
		tl_value_set_done();
	}
	
	void action_tl_frame_transition(ScopeAny self, VarType name)
	{
		tl_value_set_start(self, ID_action_tl_frame_transition, false);
		tl_value_set(self, { e_value_TRANSITION, name, false });
		tl_value_set_done();
	}
	
	void action_tl_frame_visible(ScopeAny self, VarType enable)
	{
		tl_value_set_start(self, ID_action_tl_frame_visible, false);
		tl_value_set(self, { e_value_VISIBLE, enable, false });
		tl_value_set_done();
	}
	
	void action_tl_frame_wind_influence(ScopeAny self, RealType val, VarType add)
	{
		tl_value_set_start(self, ID_action_tl_frame_wind_influence, true);
		tl_value_set(self, { e_value_WIND_INFLUENCE, val / 100.0, add });
		tl_value_set_done();
	}
	
	void action_tl_ghost(ScopeAny self, VarType timeline)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						sVar(ghost) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
			
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
							sVar(ghost) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
				
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_ghost, false);
				action_tl_ghost_tree(timeline, !(idVar(timeline, ghost) > 0), hobj);
			}
		
		
	}
	
	void action_tl_ghost_tree(VarType tl, BoolType nval, VarType hobj)
	{
		withOne (obj_history, hobj, noone)
			history_save_var(self, tl, idVar(tl, ghost), nval);
		
		idVar(tl, ghost) = nval;
		for (IntType i = IntType(0); i < ds_list_size(idInt(tl, tree_list)); i++)
			action_tl_ghost_tree(DsList(idInt(tl, tree_list)).Value(i), nval, hobj);
	}
	
	void action_tl_glint_mode(ScopeAny self, VarType mode)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						sVar(glint_mode) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
			
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
							sVar(glint_mode) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
				
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_glint_mode, false);
				withAll (obj_timeline, self->id)
					if (self->selected > 0)
						action_tl_glint_mode_tree(self->id, mode, hobj);
				
			}
		
		
	}
	
	void action_tl_glint_mode_tree(VarType tl, VarType nval, VarType hobj)
	{
		withOne (obj_history, hobj, noone)
			history_save_var(self, tl, idVar(tl, glint_mode), nval);
		
		idVar(tl, glint_mode) = nval;
		for (IntType i = IntType(0); i < ds_list_size(idInt(tl, tree_list)); i++)
			if (!(idReal(DsList(idInt(tl, tree_list)).Value(i), selected) > 0))
				action_tl_glint_mode_tree(DsList(idInt(tl, tree_list)).Value(i), nval, hobj);
	}
	
	void action_tl_glint_scale(ScopeAny self, VarType val, VarType add)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						sVar(glint_scale) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
			
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
							sVar(glint_scale) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
				
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_glint_scale, true);
				withAll (obj_timeline, self->id)
					if (self->selected > 0)
						action_tl_glint_scale_tree(self->id, val, add, hobj);
				
			}
		
		
	}
	
	void action_tl_glint_scale_tree(VarType tl, RealType nval, VarType add, VarType hobj)
	{
		withOne (obj_history, hobj, noone)
			history_save_var(self, tl, idVar(tl, glint_scale), idVar(tl, glint_scale) * add + nval / 100.0);
		
		idVar(tl, glint_scale) = idVar(tl, glint_scale) * add + nval / 100.0;
		for (IntType i = IntType(0); i < ds_list_size(idInt(tl, tree_list)); i++)
			if (!(idReal(DsList(idInt(tl, tree_list)).Value(i), selected) > 0))
				action_tl_glint_scale_tree(DsList(idInt(tl, tree_list)).Value(i), nval, add, hobj);
	}
	
	void action_tl_glint_speed(ScopeAny self, VarType val, VarType add)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						sVar(glint_speed) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
			
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
							sVar(glint_speed) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
				
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_glint_speed, true);
				withAll (obj_timeline, self->id)
					if (self->selected > 0)
						action_tl_glint_speed_tree(self->id, val, add, hobj);
				
			}
		
		
	}
	
	void action_tl_glint_speed_tree(VarType tl, RealType nval, VarType add, VarType hobj)
	{
		withOne (obj_history, hobj, noone)
			history_save_var(self, tl, idVar(tl, glint_speed), idVar(tl, glint_speed) * add + nval / 100.0);
		
		idVar(tl, glint_speed) = idVar(tl, glint_speed) * add + nval / 100.0;
		for (IntType i = IntType(0); i < ds_list_size(idInt(tl, tree_list)); i++)
			if (!(idReal(DsList(idInt(tl, tree_list)).Value(i), selected) > 0))
				action_tl_glint_speed_tree(DsList(idInt(tl, tree_list)).Value(i), nval, add, hobj);
	}
	
	void action_tl_glint_strength(ScopeAny self, VarType val, VarType add)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						sVar(glint_strength) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
			
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
							sVar(glint_strength) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
				
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_glint_strength, true);
				withAll (obj_timeline, self->id)
					if (self->selected > 0)
						action_tl_glint_strength_tree(self->id, val, add, hobj);
				
			}
		
		
	}
	
	void action_tl_glint_strength_tree(VarType tl, RealType nval, VarType add, VarType hobj)
	{
		withOne (obj_history, hobj, noone)
			history_save_var(self, tl, idVar(tl, glint_strength), idVar(tl, glint_strength) * add + nval / 100.0);
		
		idVar(tl, glint_strength) = idVar(tl, glint_strength) * add + nval / 100.0;
		for (IntType i = IntType(0); i < ds_list_size(idInt(tl, tree_list)); i++)
			if (!(idReal(DsList(idInt(tl, tree_list)).Value(i), selected) > 0))
				action_tl_glint_strength_tree(DsList(idInt(tl, tree_list)).Value(i), nval, add, hobj);
	}
	
	void action_tl_glint_tex(ScopeAny self, VarType tex)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
					{
						idInt(sVar(glint_tex), count)--;
						sVar(glint_tex) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
						idInt(sVar(glint_tex), count)++;
					}
			
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						{
							idInt(sVar(glint_tex), count)--;
							sVar(glint_tex) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
							idInt(sVar(glint_tex), count)++;
						}
				
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_glint_tex, false);
				withAll (obj_timeline, self->id)
					if (self->selected > 0)
						action_tl_glint_tex_tree(self->id, tex, hobj);
				
			}
		
		
	}
	
	void action_tl_glint_tex_tree(VarType tl, VarType nval, VarType hobj)
	{
		withOne (obj_history, hobj, noone)
			history_save_var(self, tl, idVar(tl, glint_tex), nval);
		
		idInt(idVar(tl, glint_tex), count)--;
		idVar(tl, glint_tex) = nval;
		idInt(idVar(tl, glint_tex), count)++;
		for (IntType i = IntType(0); i < ds_list_size(idInt(tl, tree_list)); i++)
			if (!(idReal(DsList(idInt(tl, tree_list)).Value(i), selected) > 0))
				action_tl_glint_tex_tree(DsList(idInt(tl, tree_list)).Value(i), nval, hobj);
	}
	
	void action_tl_glow(ScopeAny self, VarType enable)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						sVar(glow) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
			
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
							sVar(glow) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
				
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_glow, false);
				withAll (obj_timeline, self->id)
					if (self->selected > 0)
						action_tl_glow_tree(self->id, enable, hobj);
				
			}
		
		
	}
	
	void action_tl_glow_texture(ScopeAny self, VarType enable)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						sVar(glow_texture) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
			
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
							sVar(glow_texture) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
				
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_glow_texture, false);
				withAll (obj_timeline, self->id)
					if (self->selected > 0)
						action_tl_glow_texture_tree(self->id, enable, hobj);
				
			}
		
		
	}
	
	void action_tl_glow_texture_tree(VarType tl, VarType nval, VarType hobj)
	{
		withOne (obj_history, hobj, noone)
			history_save_var(self, tl, idVar(tl, glow_texture), nval);
		
		idVar(tl, glow_texture) = nval;
		for (IntType i = IntType(0); i < ds_list_size(idInt(tl, tree_list)); i++)
			if (!(idReal(DsList(idInt(tl, tree_list)).Value(i), selected) > 0))
				action_tl_glow_texture_tree(DsList(idInt(tl, tree_list)).Value(i), nval, hobj);
	}
	
	void action_tl_glow_tree(VarType tl, VarType nval, VarType hobj)
	{
		withOne (obj_history, hobj, noone)
			history_save_var(self, tl, idVar(tl, glow), nval);
		
		idVar(tl, glow) = nval;
		for (IntType i = IntType(0); i < ds_list_size(idInt(tl, tree_list)); i++)
			if (!(idReal(DsList(idInt(tl, tree_list)).Value(i), selected) > 0))
				action_tl_glow_tree(DsList(idInt(tl, tree_list)).Value(i), nval, hobj);
	}
	
	void action_tl_hide(ScopeAny self, VarType timeline)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						sVar(hide) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
			
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
							sVar(hide) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
				
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_hide, false);
				action_tl_hide_tree(timeline, !(idVar(timeline, hide) > 0), hobj);
			}
		
		
	}
	
	void action_tl_hide_select(ScopeAny self, BoolType hide)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						idVar(self->id, hide) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
			
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
							idVar(self->id, hide) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
				
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_hide_select, false);
				withAll (obj_timeline, self->id)
				{
					if (!(self->selected > 0))
						continue;
					action_tl_hide_tree(self->id, hide, hobj);
				}
				
			}
		
		
	}
	
	void action_tl_hide_tree(VarType tl, BoolType nval, VarType hobj)
	{
		withOne (obj_history, hobj, noone)
			history_save_var(self, tl, idVar(tl, hide), nval);
		
		idVar(tl, hide) = nval;
		for (IntType i = IntType(0); i < ds_list_size(idInt(tl, tree_list)); i++)
			action_tl_hide_tree(DsList(idInt(tl, tree_list)).Value(i), nval, hobj);
	}
	
	void action_tl_hq_hiding(ScopeAny self, VarType enable)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						sVar(hq_hiding) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
			
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
							sVar(hq_hiding) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
				
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_hq_hiding, false);
				withAll (obj_timeline, self->id)
					if (self->selected > 0)
						action_tl_hq_hiding_tree(self->id, enable, hobj);
				
			}
		
		
	}
	
	void action_tl_hq_hiding_tree(VarType tl, VarType nval, VarType hobj)
	{
		withOne (obj_history, hobj, noone)
			history_save_var(self, tl, idVar(tl, hq_hiding), nval);
		
		idVar(tl, hq_hiding) = nval;
		for (IntType i = IntType(0); i < ds_list_size(idInt(tl, tree_list)); i++)
			if (!(idReal(DsList(idInt(tl, tree_list)).Value(i), selected) > 0))
				action_tl_hq_hiding_tree(DsList(idInt(tl, tree_list)).Value(i), nval, hobj);
	}
	
	void action_tl_inherit_alpha(ScopeAny self, VarType enable)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
			{
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
				{
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
					{
						sVar(inherit_alpha) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
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
							sVar(inherit_alpha) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
							sBool(update_matrix) = true;
						}
						
					}
				}
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_inherit_alpha, false);
				withAll (obj_timeline, self->id)
				{
					if (!(self->selected > 0))
						continue;
					withOne (obj_history, hobj, self->id)
						history_save_var(self, self.otherId, ObjType(obj_timeline, self.otherId)->inherit_alpha, enable);
					
					self->inherit_alpha = enable;
					self->update_matrix = true;
				}
				
			}
		
		
		tl_update_matrix(self);
	}
	
	void action_tl_inherit_bend(ScopeAny self, VarType enable)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
			{
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
				{
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
					{
						sVar(inherit_bend) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
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
							sVar(inherit_bend) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
							sBool(update_matrix) = true;
						}
						
					}
				}
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_inherit_bend, IntType(0));
				withAll (obj_timeline, self->id)
				{
					if (!(self->selected > 0))
						continue;
					withOne (obj_history, hobj, self->id)
						history_save_var(self, self.otherId, ObjType(obj_timeline, self.otherId)->inherit_bend, enable);
					
					self->inherit_bend = enable;
					self->update_matrix = true;
				}
				
			}
		
		
		tl_update_matrix(self);
	}
	
	void action_tl_inherit_color(ScopeAny self, VarType enable)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
			{
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
				{
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
					{
						sVar(inherit_color) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
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
							sVar(inherit_color) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
							sBool(update_matrix) = true;
						}
						
					}
				}
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_inherit_color, false);
				withAll (obj_timeline, self->id)
				{
					if (!(self->selected > 0))
						continue;
					withOne (obj_history, hobj, self->id)
						history_save_var(self, self.otherId, ObjType(obj_timeline, self.otherId)->inherit_color, enable);
					
					self->inherit_color = enable;
					self->update_matrix = true;
				}
				
			}
		
		
		tl_update_matrix(self);
	}
	
	void action_tl_inherit_glow_color(ScopeAny self, VarType enable)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
			{
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
				{
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
					{
						sVar(inherit_glow_color) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
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
							sVar(inherit_glow_color) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
							sBool(update_matrix) = true;
						}
						
					}
				}
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_inherit_glow_color, false);
				withAll (obj_timeline, self->id)
				{
					if (!(self->selected > 0))
						continue;
					withOne (obj_history, hobj, self->id)
						history_save_var(self, self.otherId, ObjType(obj_timeline, self.otherId)->inherit_glow_color, enable);
					
					self->inherit_glow_color = enable;
					self->update_matrix = true;
				}
				
			}
		
		
		tl_update_matrix(self);
	}
	
	void action_tl_inherit_pose(ScopeAny self, VarType enable)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
			{
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
				{
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
					{
						sVar(inherit_pose) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
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
							sVar(inherit_pose) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
							sBool(update_matrix) = true;
						}
						
					}
				}
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_inherit_pose, false);
				withAll (obj_timeline, self->id)
				{
					if (!(self->selected > 0))
						continue;
					withOne (obj_history, hobj, self->id)
						history_save_var(self, self.otherId, ObjType(obj_timeline, self.otherId)->inherit_pose, enable);
					
					self->inherit_pose = enable;
					self->update_matrix = true;
				}
				
			}
		
		
		tl_update_matrix(self);
	}
	
	void action_tl_inherit_position(ScopeAny self, VarType enable)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
			{
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
				{
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
					{
						sVar(inherit_position) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
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
							sVar(inherit_position) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
							sBool(update_matrix) = true;
						}
						
					}
				}
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_inherit_position, false);
				withAll (obj_timeline, self->id)
				{
					if (!(self->selected > 0))
						continue;
					withOne (obj_history, hobj, self->id)
						history_save_var(self, self.otherId, ObjType(obj_timeline, self.otherId)->inherit_position, enable);
					
					self->inherit_position = enable;
					self->update_matrix = true;
				}
				
			}
		
		
		tl_update_matrix(self);
	}
	
	void action_tl_inherit_rotation(ScopeAny self, VarType enable)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
			{
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
				{
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
					{
						sVar(inherit_rotation) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
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
							sVar(inherit_rotation) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
							sBool(update_matrix) = true;
						}
						
					}
				}
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_inherit_rotation, IntType(0));
				withAll (obj_timeline, self->id)
				{
					if (!(self->selected > 0))
						continue;
					withOne (obj_history, hobj, self->id)
						history_save_var(self, self.otherId, ObjType(obj_timeline, self.otherId)->inherit_rotation, enable);
					
					self->inherit_rotation = enable;
					self->update_matrix = true;
				}
				
			}
		
		
		tl_update_matrix(self);
	}
	
	void action_tl_inherit_rot_point(ScopeAny self, VarType enable)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
			{
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
				{
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
					{
						sVar(inherit_rot_point) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
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
							sVar(inherit_rot_point) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
							sBool(update_matrix) = true;
						}
						
					}
				}
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_inherit_rot_point, false);
				withAll (obj_timeline, self->id)
				{
					if (!(self->selected > 0))
						continue;
					withOne (obj_history, hobj, self->id)
						history_save_var(self, self.otherId, ObjType(obj_timeline, self.otherId)->inherit_rot_point, enable);
					
					self->inherit_rot_point = enable;
					self->update_matrix = true;
				}
				
			}
		
		
		tl_update_matrix(self);
	}
	
}
