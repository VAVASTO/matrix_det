type Matrix = { values: float[,] }
    with
        static member ofArray2D (values: float [,]) = 
            { values = values }
    
    end

// type result =
//     | NiceRes of int * string

// let Umatrix (A:Matrix, rows:int, cols:int, size:int):result = 
//     if (true) then
//         let Hell = "Ass"
//         NiceRes (1, Hell)
//     else 
//         NiceRes (0, "Dick")




let size = 3
let a = array2D [[6.;2.;20.]
                 [4.;9.;6.]
                 [10.;7.;4.]]
let A = Matrix.ofArray2D a
//let Q = Umatrix(A, 2, 3, 3)
// let Text =
//     match Q with 
//     | NiceRes(1, Hell) -> Hell.ToString()
//     | NiceRes(0, "Dick") -> "Dick"
// printfn "%A" Text