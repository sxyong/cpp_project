src = $(shell ls *.cpp)
obj = $(src:.cpp=.o)
bin = a

$(bin):$(obj)
	g++ $^ -o $@

%.o:%.cpp
	g++ -g -c $< -o $@

clean:
	rm -f $(bin);
	rm -f $(obj);