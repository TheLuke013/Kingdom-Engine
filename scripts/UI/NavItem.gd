extends Control

export(StreamTexture) var icon
export var label = "Home"
export var active = false
export(NodePath) var page

var page_name
 
func _ready():
	$Icon.texture = icon
	$Label.text = label
	update_elements()

func set_active():
	active = true
	update_elements()

func deactive():
	active = false
	update_elements()

func update_elements():
	$Active.visible = active
	get_node(page).visible = active
	
	if active:
		$BG.color = "#4c3575"
	else:
		$BG.color = "#371b58"

func _on_NavItem_mouse_entered():
	$BG.color = "#4c3575"

func _on_NavItem_mouse_exited():
	update_elements()

func _on_NavItem_gui_input(event):
	if event is InputEventMouseButton:
		if event.is_pressed() and event.get_button_index() == 1:
			var navitems = get_tree().get_nodes_in_group("NavItem")
			for item in navitems:
				item.deactive()
			set_active()
