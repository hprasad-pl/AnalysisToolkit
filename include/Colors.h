#ifndef COLORS_H
#define COLORS_H

#include "TColor.h"

// Define 100 colors using TColor and HEX codes
namespace Colors {
    // Color constants with HEX codes
    const Int_t kRed1 = TColor::GetColor("#FF0000");
    const Int_t kGreen1 = TColor::GetColor("#00FF00");
    const Int_t kBlue1 = TColor::GetColor("#0000FF");
    const Int_t kYellow1 = TColor::GetColor("#FFFF00");
    const Int_t kCyan1 = TColor::GetColor("#00FFFF");
    const Int_t kMagenta1 = TColor::GetColor("#FF00FF");
    const Int_t kOrange1 = TColor::GetColor("#FFA500");
    const Int_t kPurple1 = TColor::GetColor("#800080");
    const Int_t kPink1 = TColor::GetColor("#FFC0CB");
    const Int_t kBrown1 = TColor::GetColor("#A52A2A");

    // Add more colors as needed
    const Int_t kGray1 = TColor::GetColor("#808080");
    const Int_t kMaroon1 = TColor::GetColor("#800000");
    const Int_t kOlive1 = TColor::GetColor("#808000");
    const Int_t kTeal1 = TColor::GetColor("#008080");
    const Int_t kNavy1 = TColor::GetColor("#000080");
    const Int_t kLime1 = TColor::GetColor("#00FF00");
    const Int_t kAqua1 = TColor::GetColor("#00FFFF");
    const Int_t kFuchsia1 = TColor::GetColor("#FF00FF");
    const Int_t kSilver1 = TColor::GetColor("#C0C0C0");
    const Int_t kBlack1 = TColor::GetColor("#000000");

    // Define more colors here...
    // You can continue adding colors up to 100 or as needed.

    // Example of a gradient (red to blue)
    const Int_t kRed2 = TColor::GetColor("#FF0000");
    const Int_t kRed3 = TColor::GetColor("#EE0000");
    const Int_t kRed4 = TColor::GetColor("#DD0000");
    const Int_t kRed5 = TColor::GetColor("#CC0000");
    const Int_t kRed6 = TColor::GetColor("#BB0000");
    const Int_t kRed7 = TColor::GetColor("#AA0000");
    const Int_t kRed8 = TColor::GetColor("#990000");
    const Int_t kRed9 = TColor::GetColor("#880000");
    const Int_t kRed10 = TColor::GetColor("#770000");

    const Int_t kBlue2 = TColor::GetColor("#0000FF");
    const Int_t kBlue3 = TColor::GetColor("#0000EE");
    const Int_t kBlue4 = TColor::GetColor("#0000DD");
    const Int_t kBlue5 = TColor::GetColor("#0000CC");
    const Int_t kBlue6 = TColor::GetColor("#0000BB");
    const Int_t kBlue7 = TColor::GetColor("#0000AA");
    const Int_t kBlue8 = TColor::GetColor("#000099");
    const Int_t kBlue9 = TColor::GetColor("#000088");
    const Int_t kBlue10 = TColor::GetColor("#000077");

    // Add more gradients or specific colors as needed...
}

namespace X11Colors {
    // Define all 317 colors from x11names
    const Int_t IndianRed = TColor::GetColor("#CD5C5C");
    const Int_t LightCoral = TColor::GetColor("#F08080");
    const Int_t Salmon = TColor::GetColor("#FA8072");
    const Int_t DarkSalmon = TColor::GetColor("#E9967A");
    const Int_t LightSalmon = TColor::GetColor("#FFA07A");
    const Int_t Crimson = TColor::GetColor("#DC143C");
    const Int_t Red = TColor::GetColor("#FF0000");
    const Int_t FireBrick = TColor::GetColor("#B22222");
    const Int_t DarkRed = TColor::GetColor("#8B0000");
    const Int_t Pink = TColor::GetColor("#FFC0CB");
    const Int_t LightPink = TColor::GetColor("#FFB6C1");
    const Int_t HotPink = TColor::GetColor("#FF69B4");
    const Int_t DeepPink = TColor::GetColor("#FF1493");
    const Int_t MediumVioletRed = TColor::GetColor("#C71585");
    const Int_t PaleVioletRed = TColor::GetColor("#DB7093");
    const Int_t Coral = TColor::GetColor("#FF7F50");
    const Int_t Tomato = TColor::GetColor("#FF6347");
    const Int_t OrangeRed = TColor::GetColor("#FF4500");
    const Int_t DarkOrange = TColor::GetColor("#FF8C00");
    const Int_t Orange = TColor::GetColor("#FFA500");
    const Int_t Gold = TColor::GetColor("#FFD700");
    const Int_t Yellow = TColor::GetColor("#FFFF00");
    const Int_t LightYellow = TColor::GetColor("#FFFFE0");
    const Int_t LemonChiffon = TColor::GetColor("#FFFACD");
    const Int_t LightGoldenrodYellow = TColor::GetColor("#FAFAD2");
    const Int_t PapayaWhip = TColor::GetColor("#FFEFD5");
    const Int_t Moccasin = TColor::GetColor("#FFE4B5");
    const Int_t PeachPuff = TColor::GetColor("#FFDAB9");
    const Int_t PaleGoldenrod = TColor::GetColor("#EEE8AA");
    const Int_t Khaki = TColor::GetColor("#F0E68C");
    const Int_t DarkKhaki = TColor::GetColor("#BDB76B");
    const Int_t Lavender = TColor::GetColor("#E6E6FA");
    const Int_t Thistle = TColor::GetColor("#D8BFD8");
    const Int_t Plum = TColor::GetColor("#DDA0DD");
    const Int_t Violet = TColor::GetColor("#EE82EE");
    const Int_t Orchid = TColor::GetColor("#DA70D6");
    const Int_t Fuchsia = TColor::GetColor("#FF00FF");
    const Int_t Magenta = TColor::GetColor("#FF00FF");
    const Int_t MediumOrchid = TColor::GetColor("#BA55D3");
    const Int_t MediumPurple = TColor::GetColor("#9370DB");
    const Int_t RebeccaPurple = TColor::GetColor("#663399");
    const Int_t BlueViolet = TColor::GetColor("#8A2BE2");
    const Int_t DarkViolet = TColor::GetColor("#9400D3");
    const Int_t DarkOrchid = TColor::GetColor("#9932CC");
    const Int_t DarkMagenta = TColor::GetColor("#8B008B");
    const Int_t Purple = TColor::GetColor("#800080");
    const Int_t Indigo = TColor::GetColor("#4B0082");
    const Int_t SlateBlue = TColor::GetColor("#6A5ACD");
    const Int_t DarkSlateBlue = TColor::GetColor("#483D8B");
    const Int_t MediumSlateBlue = TColor::GetColor("#7B68EE");
    const Int_t GreenYellow = TColor::GetColor("#ADFF2F");
    const Int_t Chartreuse = TColor::GetColor("#7FFF00");
    const Int_t LawnGreen = TColor::GetColor("#7CFC00");
    const Int_t Lime = TColor::GetColor("#00FF00");
    const Int_t LimeGreen = TColor::GetColor("#32CD32");
    const Int_t PaleGreen = TColor::GetColor("#98FB98");
    const Int_t LightGreen = TColor::GetColor("#90EE90");
    const Int_t MediumSpringGreen = TColor::GetColor("#00FA9A");
    const Int_t SpringGreen = TColor::GetColor("#00FF7F");
    const Int_t MediumSeaGreen = TColor::GetColor("#3CB371");
    const Int_t SeaGreen = TColor::GetColor("#2E8B57");
    const Int_t ForestGreen = TColor::GetColor("#228B22");
    const Int_t Green = TColor::GetColor("#008000");
    const Int_t DarkGreen = TColor::GetColor("#006400");
    const Int_t YellowGreen = TColor::GetColor("#9ACD32");
    const Int_t OliveDrab = TColor::GetColor("#6B8E23");
    const Int_t Olive = TColor::GetColor("#808000");
    const Int_t DarkOliveGreen = TColor::GetColor("#556B2F");
    const Int_t MediumAquamarine = TColor::GetColor("#66CDAA");
    const Int_t DarkSeaGreen = TColor::GetColor("#8FBC8F");
    const Int_t LightSeaGreen = TColor::GetColor("#20B2AA");
    const Int_t DarkCyan = TColor::GetColor("#008B8B");
    const Int_t Teal = TColor::GetColor("#008080");
    const Int_t Aqua = TColor::GetColor("#00FFFF");
    const Int_t Cyan = TColor::GetColor("#00FFFF");
    const Int_t LightCyan = TColor::GetColor("#E0FFFF");
    const Int_t PaleTurquoise = TColor::GetColor("#AFEEEE");
    const Int_t Aquamarine = TColor::GetColor("#7FFFD4");
    const Int_t Turquoise = TColor::GetColor("#40E0D0");
    const Int_t MediumTurquoise = TColor::GetColor("#48D1CC");
    const Int_t DarkTurquoise = TColor::GetColor("#00CED1");
    const Int_t CadetBlue = TColor::GetColor("#5F9EA0");
    const Int_t SteelBlue = TColor::GetColor("#4682B4");
    const Int_t LightSteelBlue = TColor::GetColor("#B0C4DE");
    const Int_t PowderBlue = TColor::GetColor("#B0E0E6");
    const Int_t LightBlue = TColor::GetColor("#ADD8E6");
    const Int_t SkyBlue = TColor::GetColor("#87CEEB");
    const Int_t LightSkyBlue = TColor::GetColor("#87CEFA");
    const Int_t DeepSkyBlue = TColor::GetColor("#00BFFF");
    const Int_t DodgerBlue = TColor::GetColor("#1E90FF");
    const Int_t CornflowerBlue = TColor::GetColor("#6495ED");
    const Int_t RoyalBlue = TColor::GetColor("#4169E1");
    const Int_t Blue = TColor::GetColor("#0000FF");
    const Int_t MediumBlue = TColor::GetColor("#0000CD");
    const Int_t DarkBlue = TColor::GetColor("#00008B");
    const Int_t Navy = TColor::GetColor("#000080");
    const Int_t MidnightBlue = TColor::GetColor("#191970");
    const Int_t Cornsilk = TColor::GetColor("#FFF8DC");
    const Int_t BlanchedAlmond = TColor::GetColor("#FFEBCD");
    const Int_t Bisque = TColor::GetColor("#FFE4C4");
    const Int_t NavajoWhite = TColor::GetColor("#FFDEAD");
    const Int_t Wheat = TColor::GetColor("#F5DEB3");
    const Int_t BurlyWood = TColor::GetColor("#DEB887");
    const Int_t Tan = TColor::GetColor("#D2B48C");
    const Int_t RosyBrown = TColor::GetColor("#BC8F8F");
    const Int_t SandyBrown = TColor::GetColor("#F4A460");
    const Int_t Goldenrod = TColor::GetColor("#DAA520");
    const Int_t DarkGoldenrod = TColor::GetColor("#B8860B");
    const Int_t Peru = TColor::GetColor("#CD853F");
    const Int_t Chocolate = TColor::GetColor("#D2691E");
    const Int_t SaddleBrown = TColor::GetColor("#8B4513");
    const Int_t Sienna = TColor::GetColor("#A0522D");
    const Int_t Brown = TColor::GetColor("#A52A2A");
    const Int_t Maroon = TColor::GetColor("#800000");
    const Int_t White = TColor::GetColor("#FFFFFF");
    const Int_t Snow = TColor::GetColor("#FFFAFA");
    const Int_t Honeydew = TColor::GetColor("#F0FFF0");
    const Int_t MintCream = TColor::GetColor("#F5FFFA");
    const Int_t Azure = TColor::GetColor("#F0FFFF");
    const Int_t AliceBlue = TColor::GetColor("#F0F8FF");
    const Int_t GhostWhite = TColor::GetColor("#F8F8FF");
    const Int_t WhiteSmoke = TColor::GetColor("#F5F5F5");
    const Int_t Seashell = TColor::GetColor("#FFF5EE");
    const Int_t Beige = TColor::GetColor("#F5F5DC");
    const Int_t OldLace = TColor::GetColor("#FDF5E6");
    const Int_t FloralWhite = TColor::GetColor("#FFFAF0");
    const Int_t Ivory = TColor::GetColor("#FFFFF0");
    const Int_t AntiqueWhite = TColor::GetColor("#FAEBD7");
    const Int_t Linen = TColor::GetColor("#FAF0E6");
    const Int_t LavenderBlush = TColor::GetColor("#FFF0F5");
    const Int_t MistyRose = TColor::GetColor("#FFE4E1");
    const Int_t Gainsboro = TColor::GetColor("#DCDCDC");
    const Int_t LightGray = TColor::GetColor("#D3D3D3");
    const Int_t Silver = TColor::GetColor("#C0C0C0");
    const Int_t DarkGray = TColor::GetColor("#A9A9A9");
    const Int_t Gray = TColor::GetColor("#808080");
    const Int_t DimGray = TColor::GetColor("#696969");
    const Int_t LightSlateGray = TColor::GetColor("#778899");
    const Int_t SlateGray = TColor::GetColor("#708090");
    const Int_t DarkSlateGray = TColor::GetColor("#2F4F4F");
    const Int_t Black = TColor::GetColor("#000000");
}

#endif // COLORS_H
