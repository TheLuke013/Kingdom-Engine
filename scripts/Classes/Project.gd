extends Node

class_name EngineProject

var project: Dictionary = {
	"project_properties": {
		"project_name": "",
		"project_path": "",
		"window_name": "",
		"window_width": 0,
		"window_height": 0
	}
}

func load_project(kep_file_path):
	#verifica se o arquivo KEP existe
	print(kep_file_path)
	var kep_file = File.new()
	if kep_file.file_exists(kep_file_path):
		#verifica se arquivo foi carregado corretamente
		var error = kep_file.open(kep_file_path, File.READ)
		if error == OK:
			#carrega conteudo e faz parse para JSON
			var content = kep_file.get_as_text()
			var json_data = JSON.parse(content).result
			
			#verifica se a analise foi bem sucesida
			if json_data != null:
				#propriedades do projeto
				var proj_prop = json_data["project_properties"]
				
				#carrega propriedades do projeto
				#e salva nos membros da classe
				if proj_prop:
					var project_prop = project["project_properties"]
					project_prop["project_name"] = proj_prop["project_name"]
					project_prop["project_path"] = proj_prop["project_path"]
					project_prop["window_name"] = proj_prop["window_name"]
					project_prop["window_width"] = proj_prop["window_width"]
					project_prop["window_height"] = proj_prop["window_height"]
					
					kep_file.close()#fecha arquivo
					KeEngine.current_project_data = project
					KeEngine.current_project_name = project["project_properties"]["project_name"]
					print("Projeto carregado com sucesso")
					
					return true
			else:
				print("Nao foi possivel carregar o projeto")
				return false
		else:
			print("Arquivo pode estar corrompido")
			return false
	else:
		print("Nao foi possivel abrir o projeto")
		return false

func create_project(project_name: String, window_w: int, window_h: int):
	#obtem o caminho da pasta de documentos do usuario
	var engine_project_folder = OS.get_system_dir(OS.SYSTEM_DIR_DOCUMENTS) + "/Kingdom Projects/"
	
	var folder = Directory.new()
	
	#verifica se existe a pasta de projetos criados na engine
	if not folder.dir_exists(engine_project_folder):
		#cria pasta dos projetos da engine
		folder.make_dir(engine_project_folder)
	
	#caminho completo para a pasta de destino
	#da criacao do projeto
	var target_project_folder = engine_project_folder + project_name
	print(target_project_folder)
		
	if not folder.dir_exists(target_project_folder):
		#cria pasta do projeto
		folder.make_dir(target_project_folder)
		
		#salva dados do projeto nos membros da classe
		var proj_prop = project["project_properties"]
		proj_prop["project_name"] = project_name
		proj_prop["project_path"] = target_project_folder
		proj_prop["window_name"] = project_name
		proj_prop["window_width"] = window_w
		proj_prop["window_height"] = window_h
		
		#salva dados do projeto
		var json_string = JSON.print(project, "    ")
		var json_file = File.new()
		
		#salva dados do projeto no arquivo KEP
		if json_file.open(target_project_folder + "/project.kep", File.WRITE) == OK:
			json_file.store_line(json_string)
			json_file.close()
		else:
			return false
		
		KeEngine.current_project_data = project
		KeEngine.current_project_name = proj_prop["project_name"]
		print("Projeto criado com sucesso")
		return true
	else:
		print("Ja existe um projeto com esse nome: ", project_name)
		return false
