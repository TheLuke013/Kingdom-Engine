extends DialogSystem

export(String) var title = "Title"
export(String) var message = "MESSAGE"

func _ready():
	$BG/Title.text = title
	$BG/MessageSpace/RichTextLabel.text = message
