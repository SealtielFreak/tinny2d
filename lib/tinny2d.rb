require_relative 'tinny2d/ext'

def random_color(n = 255)
  Array.new(3) { rand n }
end

class Game
  attr_reader :background
  include Draw

  def initialize(**kwargs, &block)
    @background = [0, 0, 0]
    @size = kwargs[:size] || [640, 480]
    @style = kwargs[:style] || 'closed'
    @title = kwargs[:sititleze] || 'tinny2d'
    @antialiasing = kwargs[:antialiasing] || 0
    @frame_rate = kwargs[:frame_rate] || 60
    @runtimes = {}
    @event = {}

    @font = Draw::Font.new 'assets/FreeMono.otf'

    block.call self
  end

  def running?
    Window.running?
  end

  def start!
    @event[:load]&.call

    Window.create @size, @title, @antialiasing
    Window.frame_rate =  @frame_rate

    @event[:open]&.call

    while Window.running?
      while Event.poll?
        name = Event.name.freeze.to_sym
        @event[name]&.call
        Window.close if name == :closed
      end

      @runtimes[:update]&.call Window.dt
      
      Draw.color = @background
      Window.clear
      @runtimes[:draw]&.call Window.dt
      Window.update
      Window.reset_time!
    end

    @event[:quit]&.call
  end

  def background=(color)
    @background = color
  end

  def puts(str)
    Draw.print(@font, str)
  end

  def event(type, &block)
    @event[type] = block
  end

  def update(&block)
    @runtimes[:update] = block
  end

  def draw(background = [0, 0, 0], &block)
    @runtimes[:draw] = block
  end
end