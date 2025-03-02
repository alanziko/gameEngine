function unitSystem(registry)
    local eventMap = getEventMap()
    local mousePos = getMousePosition(eventMap)
    local entites = getEntitiesByComponent("Position")
    for k, entity in pairs(entites) do
        local entityPosition = getPosition(entity)
        if(mousePos[1] >= entityPosition[1]*10 and mousePos[1] <= entityPosition[1]*10+10) then
            if(mousePos[2] >= entityPosition[2]*10+100 and mousePos[2] <= entityPosition[2]*10+110) then
                
            end
        end
    end
end