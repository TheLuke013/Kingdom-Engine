extends Spatial

onready var camera = $Camera

const MAX_ANGLE = 90
const MIN_ANGLE = -80

var look_rot = Vector3.ZERO
var sensitivity = 0.2
var can_move = false
var editor_is_active: bool
var zoom_level = 70
var zoom_scale = 2.0

#ZOOM
func zoom_in():
	if zoom_level > 2:
		zoom_level -= zoom_scale
		update_zoom()

func zoom_out():
	if zoom_level < 177:
		zoom_level += zoom_scale
		update_zoom()

func update_zoom():
	print(zoom_level)
	camera.fov = zoom_level

func _physics_process(_delta):
	if can_move:
		rotation_degrees.x = look_rot.x
		rotation_degrees.y = look_rot.y

func _input(event):
	if event is InputEventMouseMotion and editor_is_active:
		look_rot.y -= (event.relative.x * sensitivity)
		look_rot.x -= (event.relative.y * sensitivity)
		look_rot.x = clamp(look_rot.x, MIN_ANGLE, MAX_ANGLE)
	elif event is InputEventMouseButton:
		#MOUSE ROTATION
		if event.is_pressed() and event.get_button_index() == 2:
			Input.mouse_mode = Input.MOUSE_MODE_CAPTURED
			can_move = true
		else:
			Input.mouse_mode = Input.MOUSE_MODE_VISIBLE
			can_move = false
		
		#ZOOM
		if event.is_action_pressed("zoom_in"):
			zoom_in()
		elif event.is_action_pressed("zoom_out"):
			zoom_out()

func _process(_delta):
	editor_is_active = get_parent().editor_is_active
