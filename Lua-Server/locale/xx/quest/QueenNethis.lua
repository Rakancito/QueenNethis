quest QueenNethis begin
    state start begin
        when 20807.chat."Queen Nethis" begin
            say_title(mob_name(20807))
            say("Do you Want destroy the Queen Nethis?")

            local answer = select("Yes", "No")
            if answer == 2 then return end
            say_title(mob_name(20807))

            if not party.is_party() then
                say("Debes ser l�der de un grupo.")
                return
            end
            if not party.is_leader() then
                say("Debes ser l�der de un grupo.")
                return   
            end

            SnakeLair.Access()
        end
    
        when 20829.chat."Go to the Boss Level" begin
            say_title(mob_name(20829))
            say("Do you want go to the Boss Level?")
            local s = select("Yes", "No")
            if s == 1 then
                SnakeLair.SetDungeonStep()
            end
        end
    end
end