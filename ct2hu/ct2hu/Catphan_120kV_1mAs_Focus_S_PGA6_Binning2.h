#ifndef _Catphan_120kV_1mAs_Focus_S_PGA6_Binning2_hpp_
#define _Catphan_120kV_1mAs_Focus_S_PGA6_Binning2_hpp_

class Catphan_Focus_S_PGA6_Binning2 {
public:
    Catphan_Focus_S_PGA6_Binning2() {

    }
    double* get_kval()
    {
        return K_val;
    }
    double* get_dis()
    {
        return dis;
    }

    float* get_ct_val()
    {
        return ct_val;
    }

    float* get_Hu_val()
    {
        return Hu_val;
    }
    int get_indexLength()
    {
        return indexLength;
    }
private:
    int indexLength = 278;
    double K_val[278] = { 0.8781419871961458, 0.8787073937800076, 0.8793111028557333, 0.8799520825589235, 0.880629799903963, 0.8813433298323557, 0.8820916498821034, 0.8828734391439623, 0.8836873742649114, 0.8845320283477311, 0.8854061697347322, 0.8863081602442123, 0.887236554136119, 0.8881899983188308, 0.8891669292230097, 0.8901656710635686, 0.8911850432426718, 0.8922233473276946, 0.8932793809309221, 0.8943513178390047, 0.8954380330981336, 0.8965380831970197, 0.8976502170863836, 0.8987734816042612, 0.8999062928927387, 0.901047778062161, 0.9021968472197089, 0.9033523993344877, 0.9045136359239732, 0.905679855112371, 0.9068498218215038, 0.9080231316628905, 0.9091992702609053, 0.9103775058451172, 0.9115572052591059, 0.9127378352844795, 0.9139191776225641, 0.9151006904363516, 0.9162817189353429, 0.9174623551727007, 0.9186423684604081, 0.9198210930081788, 0.9209987241505794, 0.9221746980566815, 0.9233493175631777, 0.9245223421957629, 0.9256934196000417, 0.9268626334937501, 0.9280297382009789, 0.929194927445492, 0.9303582864001455, 0.9315195683549984, 0.9326786355722047, 0.9338356837240472, 0.9349906311223913, 0.9361435635815342, 0.9372945117797425, 0.9384433942548184, 0.9395901853848483, 0.9407350292586997, 0.9418779581013962, 0.9430191183593177, 0.9441582590492522, 0.9452953554911694, 0.9464306120584453, 0.947563890775269, 0.9486950525113628, 0.9498241300518098, 0.9509512723284761, 0.9520762820851174, 0.9531991927692579, 0.9543198053780498, 0.9554382694573229, 0.9565543850853162, 0.9576681265928862, 0.9587794682651612, 0.9598882075882296, 0.9609943175359903, 0.9620977118530593, 0.9631983037036397, 0.9642958867537369, 0.9653905509925308, 0.966482088807748, 0.9675701712122989, 0.9686548865037135, 0.9697362037708753, 0.9708138510187327, 0.9718876749041602, 0.9729577631484129, 0.9740237798719957, 0.9750854473455878, 0.976143034114962, 0.9771962007598386, 0.9782445440579872, 0.9792885162133804, 0.9803277747416779, 0.981362220926979, 0.9823916938679867, 0.9834161553674814, 0.9844355672877465, 0.9854498915536684, 0.9864589657054529, 0.9874626263384458, 0.9884608965513203, 0.9894536748262684, 0.990441047419648, 0.9914230388255172, 0.9923994222175226, 0.9933702848824214, 0.994335082965346, 0.9952941556360433, 0.9962475277815237, 0.9971951613009984, 0.9981371456240057, 0.9990734436022385, 1.0000038263652107, 1.0009285121897984, 1.0018475930055102, 1.00276077600663, 1.0036679598875247, 1.0045690430153564, 1.0054643113164423, 1.0063533407907632, 1.0072364184586036, 1.0081137037881234, 1.0089850322427891, 1.0098504993732418, 1.0107098098312846, 1.0115632555393217, 1.0124107375204718, 1.0132519595518492, 1.0140873471856144, 1.0149165387505583, 1.0157398962983017, 1.0165569916338275, 1.0173682545932548, 1.0181737203782293, 1.0189730263863623, 1.0197664065783523, 1.0205541633307567, 1.0213360008903092, 1.0221122900659723, 1.0228826682837568, 1.023647843191205, 1.0244079230264367, 1.0251622776935116, 1.0259114178083681, 1.026655520260599, 1.0273944257403567, 1.0281285826176951, 1.0288579682432026, 1.0295824244955667, 1.030302471389318, 1.0310179523251264, 1.0317288461712966, 1.0324357453346773, 1.0331382901016892, 1.0338365974004535, 1.0345309218509193, 1.0352212454944723, 1.0359076876791538, 1.0365900249909399, 1.0372683770018523, 1.0379426574020663, 1.0386130555096809, 1.0392791401685713, 1.0399408239520225, 1.040598157652461, 1.0412509845075366, 1.0418992165654999, 1.0425431131347962, 1.0431818911754491, 1.0438156697437142, 1.0444444291812562, 1.0450676610750467, 1.0456852743496738, 1.0462972477559678, 1.0469034200314273, 1.0475036995931752, 1.0480977137290985, 1.0486856509131854, 1.0492672783461343, 1.0498426444045448, 1.0504115157536054, 1.0509737996140216, 1.0515296152419105, 1.0520791534888738, 1.0526223937429142, 1.053159386520878, 1.0536900408387084, 1.0542148341689535, 1.0547341038779745, 1.0552479752764732, 1.0557563605560731, 1.0562595998450302, 1.056757891951954, 1.0572520084390604, 1.0577419369285408, 1.058228238003925, 1.0587111877279403, 1.0591907045689397, 1.0596671376165874, 1.0601415559852707, 1.0606134501580469, 1.061083532785951, 1.0615517264314505, 1.0620183861560062, 1.0624837239265394, 1.062948385972648, 1.063412153047498, 1.0638750946508746, 1.064337352974204, 1.0647989257099515, 1.0652599556790683, 1.0657204409508303, 1.0661803069044553, 1.0666394786681592, 1.0670978811198013, 1.0675552931331704, 1.068011638713731, 1.0684666956171558, 1.0689203139216163, 1.0693722700907515, 1.0698222666694728, 1.0702702249776472, 1.070715772869948, 1.0711588304852169, 1.0715990240260795, 1.0720356110733318, 1.0724689501143772, 1.0728984439688254, 1.073324082973764, 1.073745415191933, 1.0741620611683291, 1.0745741572818592, 1.0749813232106304, 1.0753831776336171, 1.0757793382656622, 1.0761696440697568, 1.0765534890910968, 1.076930933359557, 1.077302037332991, 1.077665747924899, 1.0780224214628817, 1.0783715975556822, 1.0787131125821552, 1.0790461327647933, 1.0793708656626613, 1.0796866252344437, 1.0799932463836701, 1.0802904148719523, 1.080577592282713, 1.080854314319447, 1.0811207142787314, 1.0813762533513576, 1.0816200931238358, 1.0818524422097568, 1.0820726867407362, 1.0822808867686695, 1.0824759793299719, 1.0826579502014784, 1.0828264112229176, 1.0829812747511458, 1.0831223790559807, 1.0832494132172006, 1.083362517420894, 1.0834612325365596, 1.0835455506883405, 1.083615089713865, 1.0836702944824022, 1.0837112357084786, 1.083737835052124, 1.0837499401879525, 1.0837483011923135, 1.0837326177758584, 1.0837031164520332, 1.0836604002182582, 1.0836046223680307 };
    double dis[278] = { 0.25,  0.5 ,  0.75,  1.  ,  1.25,  1.5 ,  1.75,  2.  ,  2.25,
        2.5 ,  2.75,  3.  ,  3.25,  3.5 ,  3.75,  4.  ,  4.25,  4.5 ,
        4.75,  5.  ,  5.25,  5.5 ,  5.75,  6.  ,  6.25,  6.5 ,  6.75,
        7.  ,  7.25,  7.5 ,  7.75,  8.  ,  8.25,  8.5 ,  8.75,  9.  ,
        9.25,  9.5 ,  9.75, 10.  , 10.25, 10.5 , 10.75, 11.  , 11.25,
       11.5 , 11.75, 12.  , 12.25, 12.5 , 12.75, 13.  , 13.25, 13.5 ,
       13.75, 14.  , 14.25, 14.5 , 14.75, 15.  , 15.25, 15.5 , 15.75,
       16.  , 16.25, 16.5 , 16.75, 17.  , 17.25, 17.5 , 17.75, 18.  ,
       18.25, 18.5 , 18.75, 19.  , 19.25, 19.5 , 19.75, 20.  , 20.25,
       20.5 , 20.75, 21.  , 21.25, 21.5 , 21.75, 22.  , 22.25, 22.5 ,
       22.75, 23.  , 23.25, 23.5 , 23.75, 24.  , 24.25, 24.5 , 24.75,
       25.  , 25.25, 25.5 , 25.75, 26.  , 26.25, 26.5 , 26.75, 27.  ,
       27.25, 27.5 , 27.75, 28.  , 28.25, 28.5 , 28.75, 29.  , 29.25,
       29.5 , 29.75, 30.  , 30.25, 30.5 , 30.75, 31.  , 31.25, 31.5 ,
       31.75, 32.  , 32.25, 32.5 , 32.75, 33.  , 33.25, 33.5 , 33.75,
       34.  , 34.25, 34.5 , 34.75, 35.  , 35.25, 35.5 , 35.75, 36.  ,
       36.25, 36.5 , 36.75, 37.  , 37.25, 37.5 , 37.75, 38.  , 38.25,
       38.5 , 38.75, 39.  , 39.25, 39.5 , 39.75, 40.  , 40.25, 40.5 ,
       40.75, 41.  , 41.25, 41.5 , 41.75, 42.  , 42.25, 42.5 , 42.75,
       43.  , 43.25, 43.5 , 43.75, 44.  , 44.25, 44.5 , 44.75, 45.  ,
       45.25, 45.5 , 45.75, 46.  , 46.25, 46.5 , 46.75, 47.  , 47.25,
       47.5 , 47.75, 48.  , 48.25, 48.5 , 48.75, 49.  , 49.25, 49.5 ,
       49.75, 50.  , 50.25, 50.5 , 50.75, 51.  , 51.25, 51.5 , 51.75,
       52.  , 52.25, 52.5 , 52.75, 53.  , 53.25, 53.5 , 53.75, 54.  ,
       54.25, 54.5 , 54.75, 55.  , 55.25, 55.5 , 55.75, 56.  , 56.25,
       56.5 , 56.75, 57.  , 57.25, 57.5 , 57.75, 58.  , 58.25, 58.5 ,
       58.75, 59.  , 59.25, 59.5 , 59.75, 60.  , 60.25, 60.5 , 60.75,
       61.  , 61.25, 61.5 , 61.75, 62.  , 62.25, 62.5 , 62.75, 63.  ,
       63.25, 63.5 , 63.75, 64.  , 64.25, 64.5 , 64.75, 65.  , 65.25,
       65.5 , 65.75, 66.  , 66.25, 66.5 , 66.75, 67.  , 67.25, 67.5 ,
       67.75, 68.  , 68.25, 68.5 , 68.75, 69.  , 69.25, 69.5 };

    float ct_val[5] = { 0.006057060532785577, 0.011668724444140745, 0.013919454401805998, 0.015403602145100743, 0.01925148712631704 };
    float Hu_val[5] = { -1000, -200, 0,  340 ,1000 };
};
#endif //__Catphan_120kV_1mAs_Focus_S_PGA6_Binning2__hpp_