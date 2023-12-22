extends Control

export(StreamTexture) var icon
export var label = "Button"

onready var bg = $BG
var style: StyleBoxFlat

func _ready():
	set_stylebox()
	$BG/Icon.texture = icon
	$BG/Label.text = label

func set_stylebox():
	style = StyleBoxFlat.new() #instance
	style.set_bg_color(Color("#371b58"))
	
	style.set_corner_radius_all(10)
	
	bg.set("custom_styles/panel", style) #add stylebox

func _on_Button_mouse_entered():
	style.set_bg_color(Color("#5b4b8a"))

func _on_Button_mouse_exited():
	style.set_bg_color(Color("#371b58"))
