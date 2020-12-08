-- Regresion lienal simple, hallaremos la pendiente y la interseccion 
-- Y = a + bx 
-- Primer punto Pendiente es la  (n*sum(X_i*Y_i) - sum(X_i)*sum(Y_i)) -(n*sum(X_i)^2 - (sumX_i)^2)
import Data.List(genericLength)


regresionLineal:: [Double] -> [Double] -> (Double,Double)
regresionLineal x y = (pen, int)
	where 
-- pen es pen_num/pen_demo
		pen = pen_num x y / pen_deno x
		int = interseccion pen x y

sumX :: [Double] -> Double
sumX x = sum x

sumY :: [Double] -> Double
sumY y = sum y 
--Numerador de la pendiente 
pen_num :: [Double] -> [Double] -> Double
pen_num x y = n*(sumX xy_i) - (sumX x)*(sumY y)
	where 
		n = genericLength x
		xy_i = zipWith (*) x y
--Demonimador de la pendiente 
pen_deno :: [Double] -> Double
pen_deno x = n*(sumX sumXi)  - sumXi2 
	where
		n = genericLength x
		sumXi = map (^2) x
		sumXi2 = sumX x ^ 2 

-- Y = a+bx
interseccion:: Double -> [Double] -> [Double] -> Double
interseccion pen x y  = my - (pen*mx) 
	where
		n =  genericLength x
		my  = sumY y / n
		mx 	= sumX x / n 


