extends Control

var following = false
var start_pos = Vector2()

func _on_TitleBar_gui_input(event):
	if event is InputEventMouseButton:
		if event.get_button_index() == 1:
			following = !following
			start_pos = get_local_mouse_position()
	
	if following:
		OS.set_window_position(OS.window_position + get_local_mouse_position() - start_pos)
