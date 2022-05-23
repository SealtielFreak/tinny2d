require 'tinny2d'

Game.new do |game|
  @current = 0

  game.draw @background do
    if @current > 30
      game.background = random_color
      @current = 0
    end

    @current += 1

    Draw.color = [0, 0, 0]
    game.puts 'Hello world'
  end
end.start!