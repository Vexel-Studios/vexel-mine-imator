/// action_tl_frame_copy_rot_blend(value, add)
/// @arg value
/// @arg add

function action_tl_frame_copy_rot_blend(val, add)
{
	tl_value_set_start(action_tl_frame_copy_rot_blend, true)
	tl_value_set(e_value.COPY_ROT_BLEND, val / 100, add)
	tl_value_set_done()
}
