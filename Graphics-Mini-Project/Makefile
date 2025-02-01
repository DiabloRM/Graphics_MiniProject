CXX = g++
CXXFLAGS = -framework OpenGL -framework GLUT -std=c++11 -DGL_SILENCE_DEPRECATION
SOURCES = main.cpp
TARGET = village

$(TARGET): $(SOURCES)
	$(CXX) $(SOURCES) $(CXXFLAGS) -o $(TARGET)

clean:
	rm -f $(TARGET) 