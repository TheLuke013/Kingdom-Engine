extends Control

onready var anim_player = $"../../../../../AnimationPlayer"

func _on_ToggleButton_gui_input(event):
	if event is InputEventMouseButton:
		if event.get_button_index() == 1 and event.is_pressed():
			if $"../../..".rect_min_size[0] == 70:
				anim_player.play("sidebar_anim")
			else:
				anim_player.play_backwards("sidebar_anim")
