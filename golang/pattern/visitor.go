package pattern

type IVistor interface {
	Visit()
}

type WeiBoVisitor struct {
}

func (w WeiBoVisitor) Visit() {

}

type IQIYVisitor struct {
}

func (i IQIYVisitor) Visit() {

}

type IElement interface {
	Accept(visitor IVistor)
}
