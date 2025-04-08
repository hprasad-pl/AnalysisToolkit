#ifndef FILLSTYLES_H
#define FILLSTYLES_H

namespace FillStyles {
    // Solid fill styles
    const Int_t Solid = 1001; // Solid fill (default)
    const Int_t Hollow = 0; // Hollow (no fill)

    // Patterned fill styles
    const Int_t HorizontalHatch = 3001; // Horizontal hatch
    const Int_t VerticalHatch = 3002; // Vertical hatch
    const Int_t CrossHatch = 3003; // Cross hatch
    const Int_t DiagonalHatch = 3004; // Diagonal hatch (left to right)
    const Int_t ReverseDiagonalHatch = 3005; // Diagonal hatch (right to left)
    const Int_t CrossDiagonalHatch = 3006; // Cross diagonal hatch

    // Custom fill styles
    const Int_t Custom1 = 3007; // Custom fill style 1
    const Int_t Custom2 = 3008; // Custom fill style 2
    const Int_t Custom3 = 3009; // Custom fill style 3
    const Int_t Custom4 = 3010; // Custom fill style 4
    const Int_t Custom5 = 3011; // Custom fill style 5
}

#endif // FILLSTYLES_H
