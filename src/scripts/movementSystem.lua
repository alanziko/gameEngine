function movementSystem(registry)
    local entities = getEntitiesByComponent("Position")
    local position = getPosition(entities[1])
    local mousePosition = getMousePosition()
end