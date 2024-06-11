raytracer: array.o camera.o color.o geometry.o light.o main.o material.o mesh.o png_render.o ray.o raytracer.o scene.o surface.o vector.o
	gcc -Wall -fopenmp -O3 $^ -lpng -lm -o raytracer 

%.o: %.c 
	gcc -Wall -c -fopenmp -O3 $< -o $@

clean:
	rm -f *.o output.png raytracer

array.o: array.c array.h
camera.o: camera.c camera.h
color.o: color.c color.h utils.h # <-
geometry.o: geometry.c geometry.h
light.o: light.c light.h
main.o: main.c raytracer.h png_render.h utils.h
material.o: material.c material.h
mesh.o: mesh.c mesh.h surface.h utils.h
png_render.o: png_render.c png_render.h
ray.o: ray.c ray.h
raytracer.o: raytracer.c raytracer.h ray.h
scene.o: scene.c scene.h mesh.h
surface.o: surface.c surface.h
vector.o: vector.c vector.h