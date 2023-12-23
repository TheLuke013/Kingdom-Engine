extends Node

class_name EngineProject

var project_name: String
var project_path: String
var window_name: String
var window_width: int
var window_height: int

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
				var proj_prop = json_data["project_properties"]
				
				#carrega propriedades do projeto
				#e salva nos membros da classe
				if proj_prop:
					project_name = proj_prop["name"]
					project_path = proj_prop["path"]
					window_name = proj_prop["window_name"]
					window_width = proj_prop["window_width"]
					window_height = proj_prop["window_height"]
					
					kep_file.close()
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
