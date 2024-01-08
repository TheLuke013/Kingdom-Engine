local player = Sprite("Player")
local playerX = 1

function Start()
    player:SetTexture("pop_cat.png")
    player:AddNode()

end

function Update()
    playerX = playerX + 0.1
    player:SetScale(playerX, playerX)
end