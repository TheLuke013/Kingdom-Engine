extends DialogSystem

export(String) var extension_file = "kep"

onready var file_tree = $FileDialog/FileTree
onready var path_display = $FileDialog/Top/CurrentPath
onready var back_button = $FileDialog/Top/Back
onready var file_selected_display = $FileDialog/Down/FileSelected
onready var file_ext_display = $FileDialog/Down/FileExt
onready var open_button = $FileDialog/Open
onready var cancel_button = $FileDialog/Cancel

var current_dir = OS.get_system_dir(OS.SYSTEM_DIR_DOCUMENTS)
var project_selected = false

func _ready():
	#muda texto para o nome da extemsap requerido
	var file_ext_text = ".{extension} (*.{extension})"
	file_ext_display.text = file_ext_text.format({"extension": extension_file})
	
	path_display.text = current_dir
	update_tree(current_dir)

func _process(_delta):
	if !project_selected:
		open_button.bg.set("custom_styles/panel", disable_style)

#arrasta a janela
func _on_FileDialog_gui_input(event):
	drag_box(event)

#atualiza a arvore de pastas e arquivos selecionada
func update_tree(dir_path):
	file_tree.clear()
	var dir = Directory.new()
	if dir.open(dir_path) == OK:
		dir.list_dir_begin()
		while true:
			var next = dir.get_next()
			if next == "":
				break
			
			var item_path = dir_path.plus_file(next)
			
			if dir.current_is_dir():
				file_tree.create_item().set_text(0, next)
			else:
				if item_path.get_extension() == extension_file:
					file_tree.create_item().set_text(0, next)
	
		dir.list_dir_end()

func _on_FileTree_item_selected():
	var selected_item = file_tree.get_selected()
	
	if selected_item:
		var item_name = selected_item.get_text(0)
		file_selected_display.text = item_name
		
		var item_path = current_dir.plus_file(item_name)
		#verifica se o item selecionado corresponde a extensao
		if item_path.get_extension() == extension_file:
			open_button.set_stylebox()
			project_selected = true
		else:
			project_selected = false

#vai para a pasta selecionada ao dar um duplo clique
func _on_FileTree_item_activated():
	var selected_item = file_tree.get_selected()
	
	if selected_item:
		var item_name = selected_item.get_text(0)
		var item_path = current_dir.plus_file(item_name)
		
		if Directory.new().open(item_path) == OK:
			current_dir = item_path
			path_display.text = current_dir
			update_tree(current_dir)

#se o TextEdit CurrentPath tiver seu texto alterado
func _on_CurrentPath_text_changed():
	current_dir = path_display.text
	update_tree(path_display.text)

#BACK BUTTON
func _on_Back_mouse_entered():
	back_button.color = "#4c3575"

func _on_Back_mouse_exited():
	back_button.color = "#00ffffff"

func _on_Back_gui_input(event):
	if event is InputEventMouseButton and event.is_pressed():
		go_up_one_folder()

func go_up_one_folder():
	var parent_dir = current_dir.get_base_dir()
	
	if parent_dir != "":
		current_dir = parent_dir
		path_display.text = current_dir
		update_tree(current_dir)

#BOTOES Open e Cancel
func _on_Open_gui_input(event):
	if event is InputEventMouseButton and project_selected:
		if event.is_pressed() and event.get_button_index() == 1:
			print("Abriu projeto")

func _on_Cancel_gui_input(event):
	if event is InputEventMouseButton:
		if event.is_pressed() and event.get_button_index() == 1:
			visible = false
