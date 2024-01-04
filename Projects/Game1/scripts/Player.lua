local player = Sprite("Player")
local playerX = 1

function Start()
    player:set_texture("../../icon.png")
    player:add_node()

end

function Update()
    playerX = playerX + 0.1
    player:set_scale(playerX, playerX)
end