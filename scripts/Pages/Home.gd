extends Control

func is_left_mouse_click(event):
	if event is InputEventMouseButton:
		if event.is_pressed() and event.get_button_index() == 1:
			return true
		else:
			return false
	else:
		return false

func _on_New_gui_input(event):
	if is_left_mouse_click(event) and not $OpenProject.visible:
		$CreateProject.visible = true

func _on_Open_gui_input(event):
	if is_left_mouse_click(event) and not $CreateProject.visible:
		$OpenProject.visible = true
