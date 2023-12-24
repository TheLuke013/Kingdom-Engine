extends DialogSystem

onready var line_edit_w = $Dialog/Width
onready var line_edit_h = $Dialog/Height
onready var line_edit_n = $Dialog/Name

var project_is_ok = false
var regex = RegEx.new()
var old_text = ""

func _ready():
	disable_create_button()
	regex.compile("^[0-9.]*$")

#controle dos BOTOES Create e Cancel
func _on_Create_gui_input(event):
	if event is InputEventMouseButton and project_is_ok:
		if event.is_pressed() and event.get_button_index() == 1:
			var new_project = EngineProject.new()
			
			#obtem os valores das entradas que
			#correspondem as propriedas do projeto
			var proj_n = line_edit_n.text
			var proj_window_w = int(line_edit_w.text)
			var proj_window_h = int(line_edit_h.text)
			
			if new_project.create_project(proj_n, proj_window_w, proj_window_h):
				visible = false
				KeEngine.load_project()

func _on_Cancel_gui_input(event):
	if event is InputEventMouseButton:
		if event.is_pressed() and event.get_button_index() == 1:
			visible = false

#arrasta a janela
func _on_Dialog_gui_input(event):
	drag_box(event)

func _on_Width_text_changed(new_text):
	is_a_number(new_text, line_edit_w)
	line_edits_is_empty()

func _on_Height_text_changed(new_text):
	is_a_number(new_text, line_edit_h)
	line_edits_is_empty()

func _on_Name_text_changed(_new_text):
	line_edits_is_empty()

#verifica se a entrada é numero
func is_a_number(value, line_edit):
	if regex.search(value):
		old_text = str(line_edit.text)
	else:
		line_edit.text = old_text
		line_edit.set_cursor_position(line_edit.text.length())

#verifica se as caixas de entrada estao vazias
func line_edits_is_empty():
	if line_edit_n.text.strip_edges() == "":
		disable_create_button()
	elif line_edit_w.text.strip_edges() == "":
		disable_create_button()
	elif line_edit_h.text.strip_edges() == "":
		disable_create_button()
	else:
		project_is_ok = true
		$Dialog/Create.set_stylebox()

func disable_create_button():
	project_is_ok = false
	$Dialog/Create.bg.set("custom_styles/panel", disable_style)
