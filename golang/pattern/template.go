package pattern

type WorkInterfact interface {
	GetUp()
	Work()
	Sleep()
}

type Worker struct {
	WorkInterfact
}

func NewWorker(w WorkInterfact) *Worker {
	return &Worker{WorkInterfact: w}
}

func (w *Worker) Daily() {
	w.GetUp()
	w.Work()
	w.Sleep()
}

type Coder struct {
}

func (c *Coder) GetUp() {

}

func (c *Coder) Work() {

}

func (c *Coder) Sleep() {

}
