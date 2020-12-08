sumar::[Int]->Int
sumar [ ] = 0
sumar (x:xs) = x + sumar(xs)