package main

import f "fmt"

type Geometrico interface {
	Area() float64
}

type Quadrado struct {
	A float64
}

func (obj *Quadrado) Area() float64 {
	return obj.A * obj.A
}

type Triangulo struct {
	A float64
}

func (obj *Triangulo) Area() float64 {
	return (obj.A * obj.A) / 2
}

func main(){
	objs := []Geometrico{
		&Quadrado{A: 5},
		&Triangulo{A: 5},
	}

	for _, obj := range objs {
		print(obj)
	}
}

func print(g Geometrico) {
	f.Println(g.Area())
}