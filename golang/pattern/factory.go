package pattern

import "fmt"

type Restaurant interface {
	GetFood()
}

type Donglaisun struct {
}

func (d *Donglaisun) GetFood() {
	fmt.Println("--冬来顺")
}

type QingFeng struct {
}

func (q *QingFeng) GetFood() {

	fmt.Println("---  清风")
}

func NewRestaurant(name string) Restaurant {
	switch name {
	case "donglaishun":
		return &Donglaisun{}
	case "qingfeng":
		return &QingFeng{}
	}
	return nil
}
