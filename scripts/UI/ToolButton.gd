extends ColorRect

enum TYPES {run}

export(TYPES) var types = TYPES.run
export(StreamTexture) var icon

var run_game_script = load("res://scripts/RunGame.gd")

func _ready():
	$Icon.texture = icon

func _on_ToolButton_gui_input(event):
	if event is InputEventMouseButton:
		if event.is_pressed() and event.get_button_index() == 1:
			if types == TYPES.run:
				var run_game = run_game_script.new()
				run_game.run_game()

func _on_ToolButton_mouse_entered():
	color = "#4c3575"

func _on_ToolButton_mouse_exited():
	color = "#7858a6"
