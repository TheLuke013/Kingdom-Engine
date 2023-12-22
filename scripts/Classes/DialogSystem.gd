extends Control

class_name DialogSystem

var following = false
var start_pos = Vector2()

func drag_box(event):
	if event is InputEventMouseButton:
		if event.get_button_index() == 1:
			following = !following
			start_pos = get_local_mouse_position()
	
	if following:
		var new_pos = rect_position + get_local_mouse_position() - start_pos
		set_position(new_pos)
