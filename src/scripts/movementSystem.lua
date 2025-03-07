function movementSystem(registry)
    local entity = getSelectedUnit()
    local pos = getPosition(entity)

    local rightMouseButton = getRightMouseButtonState()    
    if (rightMouseButton) then
        setPosition(entity, pos[1]+1, pos[2])
    end
end