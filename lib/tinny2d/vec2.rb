
class Vector2
    attr_accessor :x, :y
    
    def initialize(vec)
      @x = vec[0]
      @y = vec[1]
    end
  
    def to_a
      [@x, @y]
    end
  
    def length
      2
    end
  
    def at(n)
      self[n]
    end
  
    def [](n)
      case n
      when 0
        self.x
      when 1
        self.y
      end
    end
  
    def +(other)
      Vector2[self[0] + other[0], self[1] + other[1]]
    end
  
    def -(other)
      Vector2[self[0] - other[0], self[1] - other[1]]
    end
  
    def *(other)
      Vector2[self[0] * other[0], self[1] * other[1]]
    end
  
    def /(other)
      Vector2[self[0] / other[0], self[1] / other[1]]
    end
  
    def self.[](x, y)
      Vector2.new [x, y]
    end
  
    def self.sample(x, y)
      Vector2.new([rand(x), rand(y)])
    end
  end