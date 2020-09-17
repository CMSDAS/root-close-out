#pragma cling optimize 3 // Enable optimizations for the just-in-time compilation

#include "ROOT/RDF/RInterface.hxx"
#include "ROOT/RVec.hxx"

/*
 * An exemplary mini analysis
 *
 * \param  df       Initial RDataFrame node
 * \param  nevents  Number of events to be processed
 *
 * \returns         Result pointer to the booked histogram
 */
ROOT::RDF::RResultPtr<TH1D> myanalysis(ROOT::RDF::RNode df, unsigned int nevents)
{
    return df.Filter([](unsigned int n) { return n > 0; }, {"nMuon"})
             .Define("pt", [](ROOT::RVec<float>& pts) { return pts[0]; }, {"Muon_pt"})
             .Range(nevents)
             .Histo1D<float>({"", ";Leading muon pt in GeV;Count", 12, 0, 60}, "pt");
}
